/*
[数学思考](https://leetcode.cn/problems/linked-list-cycle-ii/comments/#:~:text=%E9%82%A3%E4%B9%88%E7%9B%B8%E9%81%87%E6%97%B6%EF%BC%9A%20slow%E6%8C%87%E9%92%88%E8%B5%B0%E8%BF%87%E7%9A%84%E8%8A%82%E7%82%B9%E6%95%B0%E4%B8%BA%3A%20x%20%2B%20y%EF%BC%8C%20fast%E6%8C%87%E9%92%88%E8%B5%B0%E8%BF%87%E7%9A%84%E8%8A%82%E7%82%B9%E6%95%B0%EF%BC%9A%20x%20%2B%20y%20%2B%20n%20(y%20%2B%20z)%EF%BC%8Cn%E4%B8%BAfast%E6%8C%87%E9%92%88%E5%9C%A8%E7%8E%AF%E5%86%85%E8%B5%B0%E4%BA%86n%E5%9C%88%E6%89%8D%E9%81%87%E5%88%B0slow%E6%8C%87%E9%92%88%EF%BC%8C%20%EF%BC%88y%2Bz%EF%BC%89%E4%B8%BA%20%E4%B8%80%E5%9C%88%E5%86%85%E8%8A%82%E7%82%B9%E7%9A%84%E4%B8%AA%E6%95%B0A%E3%80%82)
*/

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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL) { //若有环，肯定不存在NULL
            slow = slow->next;
            fast = fast->next->next;
            // 快慢指针相遇，此时从head 和 相遇点出发，同时查找直至相遇
            if (slow == fast) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2; // 返回环的入口
            }
        }
        return NULL;
    }
};