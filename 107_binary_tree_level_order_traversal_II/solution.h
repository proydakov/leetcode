class Solution {
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root)
    {
        std::vector<std::vector<int>> data;
        if(nullptr == root) {
            return data;
        }

        std::vector<TreeNode*> items;
        items.reserve(32);
        items.push_back(root);
        
        std::vector<TreeNode*> temp;
        temp.reserve(32);

        while(!items.empty()) {
            std::vector<int> line;
            line.reserve(32);
            for(size_t i = 0; i < items.size(); i++) {
                TreeNode* node = items[i];
                if(node) {
                    line.push_back(node->val);
                    temp.push_back(node->left);
                    temp.push_back(node->right);
                }
            }
            data.push_back(std::move(line));
            items.clear();
            items.swap(temp);
        }
        data.resize(data.size() - 1);

        std::reverse(data.begin(), data.end());
        return data;
    }
};
