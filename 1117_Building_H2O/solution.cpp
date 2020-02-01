static auto __static_initializer__ = []() {ios_base::sync_with_stdio(false); cin.tie(NULL); return nullptr; }();

class H2O
{
private:
    int h;
    std::mutex mtx_hydrogen;
    std::mutex mtx_oxygen;

public:
    H2O() : h(0) {}

    void hydrogen(std::function<void()> releaseHydrogen)
    {
        mtx_hydrogen.lock();
        h++;
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        if (h % 2) { mtx_hydrogen.unlock(); } // pair of hydrogens exist, release another hydrogen to balance oxygen released
        else { mtx_oxygen.unlock(); }
    }

    void oxygen(std::function<void()> releaseOxygen)
    {
        mtx_oxygen.lock();
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        mtx_hydrogen.unlock();
    }
};
