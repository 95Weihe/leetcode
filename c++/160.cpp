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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p, *q;
        p = headA;
        int lenA=0,lenB=0;
        while(p){
            lenA++;
            p = p->next;
        }
        p = headB;
        while(p){
            lenB++;
            p = p->next;
        }
        p = headA, q = headB;
        while(lenA>lenB){
            lenA--;
            p = p->next;
        }
        while(lenA<lenB){
            lenB--;
            q = q->next;
        }
        while(p!=q&&p){
            p = p->next;
            q = q->next;
        }
        return p;
    }
};