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
    ListNode* swapPairs(ListNode* head)
    {
        if (nullptr == head || nullptr == head->next)
        {
            return head;
        }

        auto h1 = head;
        auto h2 = head->next;

        ListNode reshead;
        ListNode* prev = &reshead;

        while (h1 != nullptr and h2 != nullptr)
        {
            auto t3 = h2->next;
            h2->next = h1;
            h1->next = t3;
            prev->next = h2;

            prev = h1;

            h1 = h1->next;
            h2 = h1 ? h1->next : nullptr;
        }

        return reshead.next;
    }
};

