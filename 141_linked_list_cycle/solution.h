#pragma once

class Solution final
{
public:
    static bool hasCycle(ListNode* head)
    {
        if (nullptr == head)
        {
            return false;
        }

        auto p1 = head;
        auto p2 = head->next;

        while (nullptr != p1 && nullptr != p2)
        {
            if (p1 == p2)
            {
                return true;
            }
            p1 = p1->next;
            p2 = p2->next;
            p2 = p2 ? p2->next : nullptr;
        }

        return false;
    }
};

