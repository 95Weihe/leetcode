package main

/**
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。

思路：与21题类似
*/
func mergeKLists(lists []*ListNode) *ListNode {
	if len(lists) == 0 {
		return nil
	}
	if len(lists) == 1 {
		return lists[0]
	}
	c := lists[0]
	for i := 1; i < len(lists); i++ {
		c = _merge(c, lists[i])
	}
	return c
}

func _merge(p *ListNode, q *ListNode) *ListNode {
	if p == nil {
		return q
	}
	if q == nil {
		return p
	}

	if p.Val < q.Val {
		p.Next = _merge(p.Next, q)
		return p
	} else {
		q.Next = _merge(p, q.Next)
	}
	return q
}
