#include <vector>
#include <iostream>

#include "tree.h"
#include "solution.h"

int main()
{
    Solution s;

    TreeNode left(0);
    TreeNode right(2);

    TreeNode head(1);
    head.left = &left;
    head.right = &right;

    std::vector<std::vector<int>> levels = s.zigzagLevelOrder(&head);
    for(size_t i = 0; i < levels.size(); i++) {
        for(size_t j = 0; j < levels[i].size(); j++) {
            std::cout << levels[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
