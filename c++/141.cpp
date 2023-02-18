/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr)
            return 0;
        ListNode *p,*q;
        p = q = head;
        while(q){
            p = p->next;
            q = q->next;
            if(q){
                q = q->next;
            }else
                return 0;
            if(p==q)
                return 1;
        }
        return 0;
    }
};