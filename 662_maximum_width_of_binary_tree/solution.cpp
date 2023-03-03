/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode* left;
 *     TreeNode* right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    std::pair<unsigned, unsigned> getNextWidth(unsigned w)
    {
        return {2 * w + 1, 2 * w + 2};
    }

    int widthOfBinaryTree(TreeNode* root)
    {
        if (nullptr == root)
        {
            return 0;
        }

        std::queue<std::pair<TreeNode*, unsigned>> queue, tmp;
        queue.push({root, 0});

        unsigned res{0};
        while(not queue.empty())
        {
            auto const x0 = queue.front().second;
            res = std::max(res, queue.back().second - queue.front().second);

            while(not queue.empty())
            {
                auto const node = queue.front();
                queue.pop();

                auto const p = node.first;
                auto const x = node.second - x0;

                auto const pair = getNextWidth(x);

                if (p->left)
                {
                    tmp.push({p->left, pair.first});
                }
                if (p->right)
                {
                    tmp.push({p->right, pair.second});
                }
            }

            queue.swap(tmp);
        }

        return res + 1;
    }
};

