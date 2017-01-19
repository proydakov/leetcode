#include <iostream>
#include "ListNode.h"
#include "solution.h"

void print(ListNode* root)
{
    ListNode* ptr = root;
    while(ptr) {
        std::cout << ptr->val << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

void test(ListNode* root)
{
    Solution s;
    print(root);
    ListNode* ptr = s.reverseList(root);
    print(ptr);
}

int main()
{
    {
        ListNode root(0);
        ListNode next1(1);
        root.next = &next1;
        ListNode next2(2);
        next1.next = &next2;
        ListNode next3(3);
        next2.next = &next3;
        ListNode next4(4);
        next3.next = &next4;
        ListNode next5(5);
        next4.next = &next5;

        test(&root);
    }

    return 0;
}
