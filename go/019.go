package main

/**
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
思路：倒数 n 个，先求总长度，然后找到idx
idx = len - n + 1  *注意删除头节点的情况 n == len head = head.next
*/
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	node, len, idx := head, 0, 0
	for node != nil {
		len++
		node = node.Next
	}
	p := head
	if p.Next == nil {
		return nil
	}
	node, idx = head.Next, len-n+1
	if n == len {
		return head.Next
	}
	for idx > 2 {
		node = node.Next
		p = p.Next
		idx--
	}
	p.Next = node.Next
	return head
}
