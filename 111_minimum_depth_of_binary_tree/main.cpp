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
    //head.right = &right;

    int depth = s.minDepth(&head);
    std::cout << "depth: " << depth << std::endl;

    return 0;
}
