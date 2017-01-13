#include <string>
#include <vector>
#include <iostream>

#include "tree.h"
#include "solution.h"

int main()
{
    Solution s;

    TreeNode node2(2);

    TreeNode node5(5);
    node2.right = &node5;

    TreeNode node3(3);

    TreeNode head(1);
    head.left = &node2;
    head.right = &node3;

    std::vector<std::string> vec = s.binaryTreePaths(&head);
    for(size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << std::endl;
    }

    return 0;
}
