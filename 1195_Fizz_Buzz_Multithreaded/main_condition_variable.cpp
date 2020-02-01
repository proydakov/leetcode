#include <mutex>
#include <thread>
#include <iostream>
#include <functional>
#include <type_traits>
#include <condition_variable>

class FizzBuzz
{
private:
    std::mutex mutex_;
    std::condition_variable cond_var_;
    int n_;
    int counter_;

public:
    FizzBuzz(int n)
        : n_(n)
        , counter_(1)
    {
    }

    // printFizz() outputs "fizz".
    void fizz(std::function<void()> printFizz)
    {
        impl([](int counter){
            return counter % 3 == 0 and counter % 5 != 0;
        }, std::move(printFizz));
    }

    // printBuzz() outputs "buzz".
    void buzz(std::function<void()> printBuzz)
    {
        impl([](int counter){
            return counter % 3 != 0 and counter % 5 == 0;
        }, std::move(printBuzz));
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(std::function<void()> printFizzBuzz)
    {
        impl([](int counter){
            return counter % 3 == 0 and counter % 5 == 0;
        }, std::move(printFizzBuzz));
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(std::function<void(int)> printNumber)
    {
        impl([](int counter){
            return counter % 3 != 0 and counter % 5 != 0;
        }, std::move(printNumber));
    }

private:
    template<typename Pred, typename Func>
    void impl(Pred pred, Func func)
    {
        while(true)
        {
            std::unique_lock<std::mutex> lock(mutex_);
            while (not pred(counter_))
            {
                if(counter_ > n_) { return; }
                cond_var_.wait(lock);
            }
            if(counter_ > n_) { break; }
            if constexpr (std::is_same<Func, std::function<void(int)>>::value)
            {
                func(counter_);
            }
            else
            {
                func();
            }
            counter_++;
            cond_var_.notify_all();
        }
    }
};

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    FizzBuzz test(std::stoi(argv[1]));

    std::thread t1([&test](){
        test.fizz([](){
            std::cout << "fizz ";
            std::cout.flush();
        });
    });

    std::thread t2([&test](){
        test.buzz([](){
            std::cout << "buzz ";
            std::cout.flush();
        });
    });

    std::thread t3([&test](){
        test.fizzbuzz([](){
            std::cout << "fizzbuzz ";
            std::cout.flush();
        });
    });

    std::thread t4([&test](){
        test.number([](int val){
            std::cout << val << ' ';
            std::cout.flush();
        });
    });

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << std::endl;

    return 0;
}
