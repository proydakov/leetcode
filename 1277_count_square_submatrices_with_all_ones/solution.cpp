class Solution
{
public:
    int countSquares(vector<vector<int>>& matrix)
    {
        if (matrix.empty())
        {
            return 0;
        }

//
//  [0,1,1,1]
//  [1,1,2,2]
//  [0,1,2,3]
//

        int res{};
        for(auto const e : matrix.front())
        {
            res += e;
        }

        size_t const yy = matrix.size();
        size_t const xx = matrix.front().size();

        for(size_t y = 1; y < yy; y++)
        {
            res += matrix[y][0];
        }

        for(size_t y = 1; y < yy; y++)
        {
            for(size_t x = 1; x < xx; x++)
            {
                if(matrix[y][x] > 0)
                {
                    matrix[y][x] += std::min({
                        matrix[y    ][x - 1],
                        matrix[y - 1][x    ],
                        matrix[y - 1][x - 1],
                    });
                    res += matrix[y][x];
                }
            }
        }

        return res;
    }
};

