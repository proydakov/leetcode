class Solution final
{
public:
    struct vertex final
    {
        int x{};
        int y{};
        int cost{};
        int obst{};
    };

    struct pair_hash final
    {
        std::size_t operator()(const std::pair<int, int> v) const
        {
            return v.first * 31 + v.second;
        }
    };

    int shortestPath(vector<vector<int>> const& grid, int k)
    {
        int const ydest = grid.size() - 1;
        int const xdest = grid.front().size() - 1;

        std::vector<std::unordered_set<std::pair<int, int>, pair_hash>> visited(k + 1);
        for(auto& set : visited)
        {
            set.reserve(grid.size() * grid.front().size());
        }

        std::queue<vertex> queue;
        queue.push({0, 0, 0, k});
        while(not queue.empty())
        {
            auto const v = queue.front();
            queue.pop();

            if (v.x >= 0 && v.x <= xdest && v.y >= 0 && v.y <= ydest)
            {
                if (v.x == xdest && v.y == ydest)
                {
                    return v.cost;
                }

                auto const next_obst = v.obst - (grid[v.y][v.x] == 1 ? 1 : 0);
                if (next_obst < 0)
                {
                    continue;
                }

                auto [it, res] = visited[v.obst].insert({v.x, v.y});
                if (not res)
                {
                    continue;
                }

                queue.push({v.x + 1, v.y    , v.cost + 1, next_obst});
                queue.push({v.x    , v.y + 1, v.cost + 1, next_obst});
                queue.push({v.x - 1, v.y    , v.cost + 1, next_obst});
                queue.push({v.x    , v.y - 1, v.cost + 1, next_obst});
            }
        }

        return -1;
    }
};

