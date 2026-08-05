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

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(!head)return false;
        ListNode *r = head;
        ListNode *n = head->next;
        while(r && n)
        {
            if (r == n)return true;
            if (r) r = r->next;
            if (n->next) n = n->next->next;
            else return false;
        }
        return false;
    }
};
