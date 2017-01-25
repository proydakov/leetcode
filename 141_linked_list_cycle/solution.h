#pragma once

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        while(ptr1) {
            ptr1 = ptr1->next;
            if(ptr1) {
                ptr1 = ptr1->next;
            }
            else {
                break;
            }
            ptr2 = ptr2->next;
            if(ptr1 == ptr2) {
                return true;
            }
        }
        return false;
    }
};
