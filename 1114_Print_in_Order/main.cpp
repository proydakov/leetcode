#include <atomic>
#include <immintrin.h>

constexpr auto core_pause = _mm_pause;

class Foo {
public:
    Foo() : counter_(0)
    {   
    }

    void first(function<void()> const& printFirst)
    {
        while (counter_.load(std::memory_order_relaxed) != 0)
        {
            core_pause();
        }
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        counter_.store(1, std::memory_order_release);
    }

    void second(function<void()> const& printSecond)
    {
        while (counter_.load(std::memory_order_relaxed) != 1)
        {
            core_pause();
        }

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        counter_.store(2, std::memory_order_release);
    }

    void third(function<void()> const& printThird)
    {
        while (counter_.load(std::memory_order_relaxed) != 2)
        {
            core_pause();
        }

        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        counter_.store(3, std::memory_order_release);
    }

private:
    std::atomic<int> counter_;
};
