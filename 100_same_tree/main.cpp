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

    const bool same = s.isSameTree(&head, &left);
    std::cout << "same: " << same << std::endl;

    return 0;
}
