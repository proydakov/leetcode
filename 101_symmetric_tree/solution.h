class Solution
{
public:
    bool isSymmetric(TreeNode* root) {
        if(nullptr == root) {
            return true;
        }
        std::vector<TreeNode*> nodes_left{ root->left };
        std::vector<TreeNode*> nodes_right{ root->right };

        std::vector<TreeNode*> ltemp;
        std::vector<TreeNode*> rtemp;

        while(!nodes_left.empty()) {
            if(nodes_left.size() != nodes_right.size()) {
                return false;
            }
            for(size_t i = 0, j = nodes_left.size() - 1; i < nodes_left.size(); i++, j--) {
                TreeNode* literm = nodes_left[i];
                TreeNode* riterm = nodes_right[i];

                if(literm == riterm) {
                    // all nullptr
                }
                else if (nullptr == literm || nullptr == riterm) {
                    return false;
                }
                else {
                    if(literm->val != riterm->val) {
                        return false;
                    }
                    ltemp.push_back(literm->left);
                    ltemp.push_back(literm->right);

                    rtemp.push_back(riterm->right);
                    rtemp.push_back(riterm->left);
                }
            }
            nodes_left.clear();
            nodes_right.clear();

            nodes_left.swap(ltemp);
            nodes_right.swap(rtemp);
        }
        return true;
    }
};
