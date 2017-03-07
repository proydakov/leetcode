
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        auto res = scan(root);
        return res.second;
    }

private:
    std::pair<int, bool> scan(TreeNode* node)
    {
        if(nullptr == node) {
            return std::make_pair(0, true);
        }
        auto left = scan(node->left);
        auto right = scan(node->right);
        bool bad = left.second && right.second;
        if(bad == false) {
            return std::make_pair(0, false);
        }
        int height = std::max(left.first, right.first) + 1;
        return std::make_pair( height, std::abs(left.first - right.first) < 2 );
    }
};
