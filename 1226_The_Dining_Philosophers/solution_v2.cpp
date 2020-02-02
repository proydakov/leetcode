#include <thread>
#include <iostream>
#include <mutex>
#include <atomic>
#include <functional>

static auto __static_initializer__ = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

struct Arbitrator
{
    Arbitrator() : mask_(0)
    {
    }

    std::atomic<std::size_t> mask_;
};

static Arbitrator g_arbitrator;

class DiningPhilosophers
{

public:
    DiningPhilosophers()
    {    
    }

    static void wantsToEat(int philosopher,
                    std::function<void()> pickLeftFork,
                    std::function<void()> pickRightFork,
                    std::function<void(int)> eat,
                    std::function<void()> putLeftFork,
                    std::function<void()> putRightFork)
    {
        while(true)
        {
            auto const mask = g_arbitrator.mask_.load(std::memory_order_relaxed);

            auto const philosopher_mask = 1 << philosopher;
            bool const i_full = mask & philosopher_mask;

            bool const initial_state = not (~0b101 & mask);
            bool const p1_full = 0b0001 & mask;
            bool const p2_full = 0b0010 & mask;
            bool const p3_full = 0b0100 & mask;
            bool const p4_full = 0b1000 & mask;

            auto const c1 = not i_full and initial_state and (0 == philosopher or 2 == philosopher);
            auto const c2 = not i_full and p1_full and p3_full and (1 == philosopher or 3 == philosopher);
            auto const c3 = not i_full and p1_full and p2_full and p3_full and p4_full and (4 == philosopher);

            if (c1 or c2)
            {
                pickLeftFork();
                pickRightFork();
                eat(philosopher);
                putLeftFork();
                putRightFork();

                g_arbitrator.mask_.fetch_or(philosopher_mask, std::memory_order_relaxed);
                break;
            }
            else if (c3)
            {
                pickLeftFork();
                pickRightFork();
                eat(philosopher);
                putLeftFork();
                putRightFork();

                g_arbitrator.mask_.store(0, std::memory_order_relaxed);
                break;
            }
            else
            {
                std::this_thread::yield();
            }
        }
        std::this_thread::yield();
    }
};

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    constexpr int philosophers = 5;

    auto const iters = std::stoi(argv[1]);

    std::vector<std::thread> threads;
    threads.reserve(philosophers);

    std::mutex mutex;
    auto lambda_eat = [&mutex](int philosopher)
    {
        std::lock_guard guard(mutex);
        std::cout << philosopher;
        std::cout.flush();
    };

    auto lambda = []()
    {
    };

    for(int i = 0; i < philosophers; i++)
    {
        threads.emplace_back([iters, lambda_eat, lambda, i](){
            DiningPhilosophers philosopher;
            for(int j = 0; j < iters; j++)
            {
                philosopher.wantsToEat(i, lambda, lambda, lambda_eat, lambda, lambda);
            }
        });
    }

    for(auto& thread : threads)
    {
        thread.join();
    }

    std::cout << std::endl;

    return 0;
}
