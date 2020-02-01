#include <mutex>
#include <thread>
#include <iostream>
#include <functional>
#include <condition_variable>

static auto __static_initializer__ = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class FooBar
{
private:
    std::mutex mutex_;
    std::condition_variable condition_variable_;
    int const n_;
    int counter_;

public:
    FooBar(int n) : n_(n * 2), counter_(0) {}

    void foo(std::function<void()> printFoo)
    {    
        impl(std::move(printFoo), 0);
    }

    void bar(std::function<void()> printBar)
    {    
        impl(std::move(printBar), 1);
    }

private:
    void impl(std::function<void()> functor, int value)
    {
        while(true)
        {
            std::unique_lock lock(mutex_);
            while(counter_ % 2 != value)
            {
                if(counter_ >= n_) { return; }
                condition_variable_.wait(lock);
            }
            if(counter_ >= n_) { break; }
            functor();
            counter_++;
            condition_variable_.notify_one();
        }
    }
};

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    FooBar test(std::stoi(argv[1]));

    std::thread t1([&test](){
        test.foo([](){
            std::cout << "foo ";
            std::cout.flush();
        });
    });

    std::thread t2([&test](){
        test.bar([](){
            std::cout << "bar ";
            std::cout.flush();
        });
    });

    t1.join();
    t2.join();

    std::cout << std::endl;

    return 0;
}
