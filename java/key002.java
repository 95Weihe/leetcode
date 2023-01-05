/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
/*给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/
        //先判断是否有一个lian'bian
        if(l1 == null) return l2;
        if(l2 == null) return l1;
        int sum = l1.val + l2.val;
        ListNode ans = new ListNode(sum % 10);
        ans.next = addTwoNumbers(l1.next ,l2.next);
        if(sum > 9){
            ans.next = addTwoNumbers(ans.next, new ListNode(1));
        }
        return ans;
    }
}
