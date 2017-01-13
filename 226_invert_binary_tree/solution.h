#pragma once

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(nullptr == root) {
            return root;
        }

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
