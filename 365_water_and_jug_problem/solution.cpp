class Solution final
{
public:
    bool canMeasureWater(int const jug1Capacity, int const jug2Capacity, int const targetCapacity)
    {
        int const l1 = jug1Capacity, l2 = jug2Capacity, ll = jug1Capacity + jug2Capacity;
        std::vector<bool> visited(ll + 1, false);

        std::array<int, 4> steps({-l1, l1, -l2, l2});

        std::queue<int> queue;
        queue.push(0);

        while(not queue.empty())
        {
            auto const v = queue.front();
            queue.pop();
            visited[v] = true;

            if (v == targetCapacity)
            {
                return true;
            }

            for(auto const s : steps)
            {
                auto const n = s + v;
                if (n >= 0 and n <= ll && visited[n] == false)
                {
                    queue.push(n);
                }
            }
        }
        return false;
    }
};

