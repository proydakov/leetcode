#pragma once

struct item {
    ListNode* ptr;
};

bool operator<(item i1, item i2)
{
    return i1.ptr->val < i2.ptr->val;
}

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode root(0);
        ListNode* ptr = &root;

        std::multiset<item> set;

        for(size_t i = 0; i < lists.size(); i++) {
            ListNode* next = lists[i];
            if(next) {
                set.insert( item{ next } );
            }
        }

        while(!set.empty()) {
            auto it = set.begin();

            ptr->next = (*it).ptr;
            ptr = ptr->next;

            ListNode* next = (*it).ptr->next;
            if(next) {
                set.insert(item{ next });
            }
            set.erase(it);
        }

        return root.next;
    }
};
