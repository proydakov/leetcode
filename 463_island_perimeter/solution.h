#pragma once

#include <vector>

class Solution {
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        if(grid.empty()) {
            return 0;
        }
        int perimeter = 0;
        const size_t h_size = grid.size();
        const size_t w_size = grid[0].size();
        for(size_t h = 0; h < h_size; h++) {
            for(size_t w = 0; w < w_size; w++) {
                if(grid[h][w]) {
                    perimeter += 4;
                    perimeter -= getNeighbors(grid, w, h, h_size, w_size);
                }
            }
        }
        return perimeter;
    }

    int getNeighbors(const std::vector<std::vector<int>>& grid, int x, int y, size_t h_size, size_t w_size) {
        int neighbors = 0;

        // point 1
        {
            int x1 = x - 1;
            int y1 = y;
            //std::cout << "x1: " << x1 << " y1: " << y1 << std::endl;
            if(x1 >= 0 && x1 < w_size) {
                neighbors += grid[y1][x1];
            }
        }

        // point 2
        {
            int x2 = x + 1;
            int y2 = y;
            //std::cout << "x2: " << x2 << " y2: " << y2 << std::endl;
            if(x2 >= 0 && x2 < w_size) {
                neighbors += grid[y2][x2];
            }
        }

        // point 3
        {
            int x3 = x;
            int y3 = y - 1;
            //std::cout << "x3: " << x3 << " y3: " << y3 << std::endl;
            if(y3 >= 0 && y3 < h_size) {
                neighbors += grid[y3][x3];
            }
        }

        // point 4
        {
            int x4 = x;
            int y4 = y + 1;
            //std::cout << "x4: " << x4 << " y4: " << y4 << std::endl;
            if(y4 >= 0 && y4 < h_size) {
                neighbors += grid[y4][x4];
            }
        }
        return neighbors;
    }
};
