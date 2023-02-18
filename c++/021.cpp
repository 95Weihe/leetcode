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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* L = nullptr;
        ListNode *p=list1, *q=list2 ,*t;
        if(!p) return q;
        if(!q) return p;
        while(p&&q){
            if(p->val<q->val){
                if(!L){
                    t = L = p;
                }else{
                    t->next = p;
                    t = p;
                }
                p=p->next;
            }else{
                if(!L){
                    t = L = q;
                }else{
                    t->next = q;
                    t = q;
                }
                q = q->next;
            }
        }
        if(p){
            t->next = p;
        }else{
            t->next = q;
        }
        return L;
    }
};