#include <atomic>
#include <thread>
#include <iostream>
#include <functional>

class ZeroEvenOdd
{
private:
    std::atomic<int> counter_;
    int n_;

public:
    ZeroEvenOdd(int n) : counter_(0), n_(n * 2)
    {
    }

    void zero(std::function<void(int)> printNumber)
    {
        impl<true>(std::move(printNumber), 0);
    }

    void even(std::function<void(int)> printNumber)
    {
        impl<false>(std::move(printNumber), 1);
    }

    void odd(std::function<void(int)> printNumber)
    {
        impl<false>(std::move(printNumber), 0);
    }

private:
    template<bool zero>
    void impl(std::function<void(int)> functor, int counter)
    {
        for(auto val = counter_.load(std::memory_order_relaxed); val < n_; val = counter_.load(std::memory_order_relaxed))
        {
            if constexpr (zero)
            {
                if (val % 2 == 0)
                {
                    functor(0);
                    counter_.fetch_add(1, std::memory_order_release);
                }
            }
            else
            {
                if (val % 2 == 1)
                {
                    auto const half = (val / 2);
                    if (half % 2 == counter)
                    {
                        functor(half + 1);
                        counter_.fetch_add(1, std::memory_order_release);
                    }
                }
            }
            std::this_thread::yield();
        }
    }
};

int main(int argc, char* argv[])
{
    std::ios_base::sync_with_stdio(false);

    if (argc != 2)
    {
        std::cerr << "usage: app <number>" << std::endl;
        return 1;
    }

    ZeroEvenOdd test(std::stoi(argv[1]));

    auto functor = [](int number){
        std::cout << number;
    };

    std::thread t0([&test, &functor](){
        test.zero(functor);
    });

    std::thread t1([&test, &functor](){
        test.even(functor);
    });

    std::thread t2([&test, &functor](){
        test.odd(functor);
    });

    t0.join();
    t1.join();
    t2.join();

    std::cout << std::endl;

    return 0;
}
