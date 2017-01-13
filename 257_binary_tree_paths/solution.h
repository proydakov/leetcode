#pragma once

#include <sstream>

class Solution {
public:
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> vec;

        if(nullptr == root) {
            return vec;
        }

        bool last;
        calcPath(root, "", vec);

        return vec;
    }

private:
    void calcPath(TreeNode* node, std::string str, std::vector<std::string>& vec) {
        if(nullptr == node) {
            return;
        }

        std::stringstream sstream;
        sstream << str;
        if(!str.empty()) {
            sstream << "->";
        }
        sstream << node->val;

        std::string str2 = sstream.str();
        if(nullptr == node->left && nullptr == node->right) {
            vec.push_back(str2);
            return;
        }

        calcPath(node->left, str2, vec);
        calcPath(node->right, str2, vec);
    }
};
