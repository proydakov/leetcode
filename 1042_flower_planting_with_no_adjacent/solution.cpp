class Solution
{
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths)
    {
        std::vector<std::vector<int>> mat(n + 1);
        for(auto const& p : paths)
        {
            mat[p.front()].push_back(p.back());
            mat[p.back()].push_back(p.front());
        }

        std::vector<char> colors(n + 1, '0');
        for(int k = 1; k <= n; k++)
        {
            if (colors[k] != '0')
            {
                continue;
            }

            std::queue<int> queue;
            queue.push(k);
            while(not queue.empty())
            {
                auto const e = queue.front();
                queue.pop();

                if (colors[e] == '0')
                {
                    std::string nc("1234");
                    auto const& room = mat[e];
                    for(auto const r : room)
                    {
                        nc.erase(std::remove(nc.begin(), nc.end(), colors[r]), nc.end());
                        queue.push(r);
                    }
                    colors[e] = nc.front();
                }
            }
        }

        std::vector<int> result(n);
        for(size_t i = 1; i <= n; i++)
        {
            result[i - 1] = static_cast<int>(colors[i] - '0');
        }
        return result;
    }
};

