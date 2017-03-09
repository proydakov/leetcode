class Solution
{
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> data;
        if(nullptr == root) {
            return data;
        }
        std::vector<TreeNode*> items;
        items.reserve(32);
        items.push_back(root);

        std::vector<TreeNode*> temp;
        temp.reserve(32);

        while(!items.empty()) {
            for(size_t i = 0; i < items.size(); i++) {
                TreeNode* node = items[i];

                if(node->left) {
                    temp.push_back(node->left);
                }
                if(node->right) {
                    temp.push_back(node->right);
                }
            }
            data.push_back(items[ items.size() - 1 ]->val);
            items.clear();
            items.swap(temp);
        }

        return data;
    }
};
