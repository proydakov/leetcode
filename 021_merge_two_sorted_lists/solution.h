#pragma once

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode root(0);
        ListNode* ptr = &root;

        while(l1 && l2) {
            if(l1->val < l2->val) {
                ptr->next = l1;
                l1 = l1->next;
            }
            else {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }

        ptr->next = l1 ? l1 : l2;
        return root.next;
    }
};
