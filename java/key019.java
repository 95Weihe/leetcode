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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        /*
        * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
        *
        * */
        ListNode fast = head;
        ListNode slow = head;
        //fast移n步，
        for (int i = 0; i < n; i++)
            fast = fast.next;
        //如果fast为空，表示删除的是头结点
        if (fast == null)
            return head.next;
        //将fast和slowt同时移动，直到fast为null
        //下一个节点就是要删除的
        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        slow.next = slow.next.next;
        return slow;
    }
}