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
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)
            return head;
        head_insert(head);
        return head;
    }
    void head_insert(ListNode*& h){
        ListNode *p=h->next, *t;
        h->next = nullptr;
        while(p){
            t = p->next;
            p->next = h;
            h = p;
            p = t;
        }
    }
};