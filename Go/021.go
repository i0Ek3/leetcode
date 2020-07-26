func mergeTwoLists(l1, l2 *ListNode) *ListNode {
	preHead := &ListNode{}
	res := preHead

	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			preHead.Next = l1
			l1 = l1.Next
		} else {
			preHead.Next = l2
			l2 = l2.Next
		}
		preHead = preHead.Next
	}

	// 其中任一链表为空
	if l1 != nil {
		preHead.Next = l1
	}

	if l2 != nil {
		preHead.Next = l2
	}

	return res.Next
}
