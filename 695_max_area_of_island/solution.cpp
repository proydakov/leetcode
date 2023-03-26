class Solution final
{
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int res{};

        for(size_t y = 0; y < grid.size(); y++)
        {
            for(size_t x = 0; x < grid[y].size(); x++)
            {
                if (1 == grid[y][x])
                {
                    res = std::max(res, mark(grid, x, y));
                }
            }
        }

        return res;
    }

    int mark(vector<vector<int>>& grid, int32_t x, int32_t y)
    {
        std::queue<std::pair<int32_t, int32_t>> queue;
        queue.push({x, y});

        int res{};
        while(not queue.empty())
        {
            auto [xi, yi] = queue.front();
            queue.pop();

            if (xi >= 0 && xi < grid.front().size() &&
                yi >= 0 && yi < grid.size() && grid[yi][xi] == 1)
            {
                res++;
                grid[yi][xi] = 2;

                queue.push({xi, yi + 1});
                queue.push({xi, yi - 1});
                queue.push({xi + 1, yi});
                queue.push({xi - 1, yi});
            }
        }

        return res;
    }
};

