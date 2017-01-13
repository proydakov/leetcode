#pragma once

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(nullptr == p && nullptr == q) {
            return true;
        }
        if(nullptr != p && nullptr != q) {
            return (p->val == q->val) &&
                    isSameTree(p->left, q->left) &&
                    isSameTree(p->right, q->right);
        }
        return false;
    }
};
