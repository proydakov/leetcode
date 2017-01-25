#pragma once

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr = head;
        while(ptr) {
            if(ptr->next && ptr->next->val == ptr->val) {
                ptr->next = ptr->next->next;
            }
            else {
                ptr = ptr->next;
            }
        }
        return head;
    }
};

