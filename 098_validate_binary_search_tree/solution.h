#pragma once

#include <limits>

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTStep(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    }

    bool isValidBSTStep(TreeNode* root, int left, int right) {
        if(nullptr == root) {
            return true;
        }

        if(root->val == std::numeric_limits<int>::min() && root->left != nullptr && root->left->val == std::numeric_limits<int>::min() ) {
            return false;
        }

        if(root->val == std::numeric_limits<int>::min() && root->left != nullptr && root->left->val == std::numeric_limits<int>::max() ) {
            return false;
        }

        if(root->val == std::numeric_limits<int>::max() && root->right != nullptr && root->right->val == std::numeric_limits<int>::max() ) {
            return false;
        }

        if(root->val == std::numeric_limits<int>::max() && root->right != nullptr && root->right->val == std::numeric_limits<int>::min() ) {
            return false;
        }

        if(root->val < left || root->val > right) {
            return false;
        }

        return isValidBSTStep(root->left, left, root->val - 1) && isValidBSTStep(root->right, root->val + 1, right);
    }
};
