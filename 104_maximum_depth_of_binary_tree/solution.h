#pragma once

#include <cmath>

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        return 1 + std::max( maxDepth(root->left), maxDepth(root->right) );
    }
};
