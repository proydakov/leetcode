#include <cmath>
#include <vector>
#include <iostream>

#include "tree.h"
#include "solution.h"

int maxDepth(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }
    return 1 + std::max( maxDepth(root->left), maxDepth(root->right) );
}

void trace(std::vector<TreeNode*> vec, int depth)
{
    for(size_t j = 0; j < std::ceil( 1.0 * depth / 2 ); j++) {
        std::cout << " ";
    }

    for(size_t i = 0; i < vec.size(); i++) {
        if(vec[i]) {
            std::cout << vec[i]->val;
        }
        else {
            std::cout << "*";
        }
        for(size_t j = 0; j < depth; j++) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    bool done = true;
    std::vector<TreeNode*> vec2;
    for(size_t i = 0; i < vec.size(); i++) {
        if(vec[i]) {
            vec2.push_back(vec[i]->left);
            vec2.push_back(vec[i]->right);
            done = false;
        }
        else {
            vec2.push_back(nullptr);
            vec2.push_back(nullptr);
        }
    }
    if(done) {
        return;
    }
    trace(vec2, depth - 1);
}

void trace(TreeNode* node)
{
    int depth = maxDepth(node);
    std::vector<TreeNode*> vec;
    vec.push_back(node);
    trace(vec, depth);
}

int main()
{
    Solution s;

////

    TreeNode node2(2);

    TreeNode node1(1);
    TreeNode node3(3);

    node2.left = &node1;
    node2.right = &node3;

////

    TreeNode node7(7);

    TreeNode node6(6);
    TreeNode node9(9);

    node7.left = &node6;
    node7.right = &node9;

////

    TreeNode head(4);
    head.left = &node2;
    head.right = &node7;

    TreeNode* node = s.invertTree(&head);
    trace(node);

    return 0;
}
