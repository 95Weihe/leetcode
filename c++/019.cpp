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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p,*q,*pre;
        int cn=0;
        p=q=head;
        while(q){
            if(cn>=n){
                pre = p;
                p = p->next;
            }
            q = q->next;
            cn++;
        }
        if(cn==n){
            p = head;
            head = head->next;
            delete p;
        }else if(cn>n){
            pre->next = p->next;
            delete p;
        }
        return head;
    }
};