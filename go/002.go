package main

/*
	给你两个非空 的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存一位数字。
	请你将两个数相加，并以相同形式返回一个表示和的链表。
	你可以假设除了数字 0 之外，这两个数都不会以 0开头
*/
func addTwoNumbers(l1 *ListNode, l2 *ListNode) (head *ListNode) {
	var tail *ListNode
	t := 0
	for l1 != nil || l2 != nil {
		x, y := 0, 0
		if l1 != nil {
			x = l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			y = l2.Val
			l2 = l2.Next
		}
		sum := x + y + t
		sum, t = sum%10, sum/10

		if head == nil {
			head = &ListNode{Val: sum}
			tail = head
		} else {
			tail.Next = &ListNode{Val: sum}
			tail = tail.Next
		}

	}
	if t > 0 {
		tail.Next = &ListNode{Val: t}
	}
	return
}
