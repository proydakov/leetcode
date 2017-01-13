#pragma once

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res_vec;

        if(nullptr == root) {
            return res_vec;
        }

        std::vector<TreeNode*> node_vec;
        node_vec.push_back(root);

        while(!node_vec.empty()) {
            std::vector<TreeNode*> temp_vec;
            temp_vec.swap(node_vec);

            std::vector<int> data;
            for(size_t i = 0; i < temp_vec.size(); i++) {
                data.push_back(temp_vec[i]->val);
                if(temp_vec[i]->left != nullptr) {
                    node_vec.push_back(temp_vec[i]->left);
                }
                if(temp_vec[i]->right != nullptr) {
                    node_vec.push_back(temp_vec[i]->right);
                }
            }
            res_vec.push_back( std::move( data ) );
        }

        return res_vec;
    }
};
