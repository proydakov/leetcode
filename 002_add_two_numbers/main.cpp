class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;

        ListNode* result = new ListNode(0);
        ListNode* head = result;

        bool extra = false;
        while(true) {
            int val1 = 0;
            int val2 = 0;
            
            if(ptr1) {
                val1 = ptr1->val;
            }
            
            if(ptr2) {
                val2 = ptr2->val;
            }
            
            result->val = val1 + val2;
            if(extra) {
                result->val += 1;
            }
            if(result->val > 9) {
                result->val = result->val % 10;
                extra = true;
            }
            else {
                extra = false;
            }
            if(ptr1) {
            ptr1 = ptr1->next;
            }
            if(ptr2) {
            ptr2 = ptr2->next;
            }
            if(ptr1 == nullptr && ptr2 == nullptr) {
                if(extra) {
                    result->next = new ListNode(1);  
                }
                break;
            }
            result->next = new ListNode(0);
            result = result->next;
        }

        return head;
    }
};