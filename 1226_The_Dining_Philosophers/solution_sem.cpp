#include <semaphore.h>

#include <thread>
#include <mutex>
#include <iostream>
#include <functional>

#define NUM_PHILOSOPHERS 5
#define LEFT (philosopher)
#define RIGHT ((philosopher + 4) % NUM_PHILOSOPHERS)

class DiningPhilosophers
{
private:
    sem_t semPhil[NUM_PHILOSOPHERS];

public:
    DiningPhilosophers()
    {
        for (int i = 0; i < NUM_PHILOSOPHERS; i++)
        {
            sem_init(&semPhil[i], 0, 1);
        }
    }

    void wantsToEat(int philosopher,
                    std::function<void()> pickLeftFork,
                    std::function<void()> pickRightFork,
                    std::function<void(int)> eat,
                    std::function<void()> putLeftFork,
                    std::function<void()> putRightFork)
    {
        int const first = (philosopher % 2 == 0) ? LEFT : RIGHT;
        int const second = LEFT + RIGHT - first;

        sem_wait(&semPhil[first]);
        sem_wait(&semPhil[second]);

        pickLeftFork();
        pickRightFork();
        eat(philosopher);
        putLeftFork();
        putRightFork();

        sem_post(&semPhil[first]);
        sem_post(&semPhil[second]);
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

    DiningPhilosophers philosopher;
    for(int i = 0; i < philosophers; i++)
    {
        threads.emplace_back([&philosopher, iters, lambda_eat, lambda, i](){
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
