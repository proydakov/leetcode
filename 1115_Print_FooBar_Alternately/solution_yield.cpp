static auto __static_initializer__ = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class FooBar
{
private:
    int const n_;
    std::atomic<int> counter_;

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
        for (auto val = counter_.load(std::memory_order_relaxed); val < n_; val = counter_.load(std::memory_order_relaxed))
        {            
            if (val % 2 == value)
            {
                functor();
                counter_.fetch_add(1, std::memory_order_release);
            }
            else
            {
                std::this_thread::yield();
            }
        }
    }
};
