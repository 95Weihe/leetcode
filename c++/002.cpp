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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2, *t;
        ListNode *l3 = new ListNode(-1);
        // cout << l3->val;
        int cn=0;
        while(p1||p2){
            int a = p1==0?0:p1->val;
            int b = p2==0?0:p2->val;
            int sum = a+b+cn;
            ListNode *q = new ListNode(sum%10);
            cn = sum/10;
            if(l3->val<0){
                l3 = t = q;
            }else {
                t->next = q;
                t = q;
            }
            p1 = p1==0?p1:p1->next;
            p2 = p2==0?p2:p2->next;
        }
        if(cn){
            ListNode *q = new ListNode(cn);
            t->next = q;
        }
        return l3;
    }
};