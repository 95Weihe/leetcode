package main

/**
合并两个有序链表
思路：根据题意模拟即可
*/

func mergeTwoLists(p *ListNode, q *ListNode) *ListNode {
	if p == nil {
		return q
	}
	if q == nil {
		return p
	}

	if p.Val < q.Val {
		p.Next = mergeTwoLists(p.Next, q)
		return p
	} else {
		q.Next = mergeTwoLists(p, q.Next)
	}
	return q
}
