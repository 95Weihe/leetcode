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
    // 定位中结点
    // ListNode* midNode(ListNode* h){
    //     ListNode* slow=h, *fast=h;
    //     while(fast&&fast->next){
    //         slow = slow->next;
    //         fast = fast->next->next;
    //     }
    //     return slow;
    // }
public:
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        ListNode* slow=head, *fast=head;
        while(fast&&fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* p, *q;
        p = head->next;
        head->next = nullptr;
        while(p!=slow){
            ListNode* t = p->next;
            p->next = head;
            head = p;
            p = t;
        }
        p = head;
        if(!fast){  //偶数个
            q = slow;
        }else{  //奇数个
            q = slow->next;
        }
        while(p&&q){
            if(p->val!=q->val)
                return false;
            p=p->next;
            q=q->next;
        }
        return true;
    }
};