#pragma once

class Solution
{
public:
    ListNode* reverseList(ListNode* current) {
        ListNode* prev = nullptr;
        while(current) {
            ListNode* temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        return prev;
    }
};
