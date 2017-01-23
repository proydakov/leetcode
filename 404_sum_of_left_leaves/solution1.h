#pragma once

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        return sumOfLeftLeaves(root->left, root) + sumOfLeftLeaves(root->right, root);
    }

private:
    int sumOfLeftLeaves(TreeNode* item, TreeNode* head) {
        if(item == nullptr) {
            return 0;
        }
        if(item->left == nullptr && item->right == nullptr) {
            if(item == head->left) {
                return item->val;
            }
            else {
                return 0;
            }
        }
        return sumOfLeftLeaves(item->left, item) + sumOfLeftLeaves(item->right, item);
    }
};
