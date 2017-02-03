#pragma once

#include <vector>

class BSTIterator {
public:
    BSTIterator(TreeNode* root) : counter_(0), size_(0) {
        push(root);
        size_ = data_.size();
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return counter_ < size_;
    }

    /** @return the next smallest number */
    int next() {
        return data_[counter_++];
    }

private:
    void push(TreeNode* root) {
        if(root) {
            push(root->left);
            data_.push_back(root->val);
            push(root->right);
        }
    }

private:
    std::vector<int> data_;
    size_t counter_;
    size_t size_;
};
