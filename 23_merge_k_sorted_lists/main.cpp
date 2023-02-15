/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*> const& lists)
    {
        auto cmp = [](ListNode* const p1, ListNode* const p2)
        {
            return (p1->val) < (p2->val);
        };
        std::multiset<ListNode*, decltype(cmp)> set(cmp);

        for(ListNode* ptr : lists)
        {
            if (ptr != nullptr)
            {
                set.insert(ptr);
            }
        }

        if (set.empty())
        {
            return nullptr;
        }

        auto tryAppendNext = [&set](auto it)
        {
            ListNode* curr = *it;
            ListNode* next = curr->next;
            set.erase(it);
            if (next != nullptr)
            {
                set.insert(next);
            }
        };

        ListNode head;
        head.next = *set.begin();
        ListNode* raw = *set.begin();

        tryAppendNext(set.begin());

        while (not set.empty())
        {
            auto it = set.begin();
            ListNode* curr = *it;

            raw->next = curr;
            raw = raw->next;

            tryAppendNext(it);
        }

        return head.next;
    }
};

