#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <functional>

static auto __static_initializer__ = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

struct Arbitrator
{
    std::mutex mutex_;
    std::condition_variable condition_variable_;
    std::size_t counter_;
};

static Arbitrator arbitr;

class DiningPhilosophers
{
public:
    DiningPhilosophers()
    {    
    }

    void wantsToEat(int philosopher,
                    std::function<void()> pickLeftFork,
                    std::function<void()> pickRightFork,
                    std::function<void(int)> eat,
                    std::function<void()> putLeftFork,
                    std::function<void()> putRightFork)
    {
        std::unique_lock lock(arbitr.mutex_);
        arbitr.condition_variable_.wait(lock, [philosopher](){
            return (arbitr.counter_ % 5) == philosopher;
        });
        pickLeftFork();
        pickRightFork();
        eat(philosopher);
        putLeftFork();
        putRightFork();
        arbitr.counter_++;
        arbitr.condition_variable_.notify_all();
    }
};

int main()
{
    std::vector<std::thread> threads;
    threads.reserve(5);

    auto lambda_eat = [](int philosopher)
    {
        std::cout << philosopher;
        std::cout.flush();
    };

    auto lambda = []()
    {
    };

    for(int i = 0; i < 5; i++)
    {
        threads.emplace_back([lambda_eat, lambda, i](){
            DiningPhilosophers philosopher;
            philosopher.wantsToEat(i, lambda, lambda, lambda_eat, lambda, lambda);
        });
    }

    for(auto& thread : threads)
    {
        thread.join();
    }

    std::cout << std::endl;

    return 0;
}
