#include <atomic>
#include <thread>
#include <iostream>
#include <functional>
#include <immintrin.h>
#include <type_traits>

class FizzBuzz
{
private:
    int n_;
    std::atomic<int> counter_;

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
        bool done = false;
        while(not done)
        {
            auto val = counter_.load(std::memory_order_relaxed);
            if (pred(val))
            {
                if(counter_ > n_)
                {
                    break;
                }
                if constexpr (std::is_same<Func, std::function<void(int)>>::value)
                {
                    func(val);
                }
                else
                {
                    func();
                }
                counter_.fetch_add(1, std::memory_order_release);
            }
            else if(counter_ > n_)
            {
                done = true;
            }
            else
            {
                _mm_pause();
            }
        }
    }
};

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "usage: app <num>" << std::endl;
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
