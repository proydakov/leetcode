#pragma once

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        if(root != nullptr) {
            if( isEnd(root->left) ) {
                res += root->left->val;
            }
            else {
                res += sumOfLeftLeaves(root->left);
            }
            res += sumOfLeftLeaves(root->right);
        }
        return res;
    }

private:
    bool isEnd(TreeNode* node) {
        if(node == nullptr) {
            return false;
        }
        if(node->left == nullptr && node->right == nullptr) {
            return true;
        }
        return false;
    }
};
