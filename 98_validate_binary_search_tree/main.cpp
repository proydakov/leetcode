#include <iostream>

#include "three.h"
#include "solution.h"

int main()
{
    Solution s;

    {
        TreeNode node_2(2);
        TreeNode node_1(1);
        TreeNode node_3(3);

        node_2.left = &node_1;
        node_2.right = &node_3;

        bool valid = s.isValidBST(&node_2);
        std::cout << "isValidBST: " << std::boolalpha << valid << std::endl;
    }

    {
        TreeNode node_1(1);
        TreeNode node_2(2);
        TreeNode node_3(3);

        node_1.left = &node_2;
        node_1.right = &node_3;

        bool valid = s.isValidBST(&node_1);
        std::cout << "isValidBST: " << std::boolalpha << valid << std::endl;
    }

    {
        TreeNode node_root(-2147483648);
        TreeNode node_right(-2147483648);

        node_root.left = &node_right;
        bool valid = s.isValidBST(&node_root);
        std::cout << "isValidBST: " << std::boolalpha << valid << std::endl;
    }

    return 0;
}
