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
//优先队列：存储每个链表的第一个结点及其值
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        if(lists.size()==1) return lists[0];
        //分冶法，类似于归并排序
        return merge(lists,0,lists.size()-1);
    }

    ListNode* merge(vector<ListNode*>& lists,int l, int h){
        if(l==h) return lists[l];
        if(l>h) return nullptr;
        int m = (l+h)>>1;
        return mergeTwo(merge(lists,l,m),merge(lists,m+1,h));
    }

    ListNode* mergeTwo(ListNode* A, ListNode* B){
        ListNode *h = new ListNode(0);
        ListNode *a=A, *b=B, *p=h;
        while(a&&b){
            if(a->val<b->val){
                p->next = a;
                p=a;
                a=a->next;
            }else{
                p->next = b;
                p = b;
                b = b->next;
            }
        }
        if(a) p->next = a;
        else p->next = b;
        return h->next;
    }
};