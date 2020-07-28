func addTwoNumbers(l1, l2 *ListNode) *ListNode {
	list := &ListNode{0, nil}
	res := list
	flag := 0

	for l1 != nil || l2 != nul || flag != 0 {
		if l1 != nil {
			flag += l1.Val
			l1 = l1.Next
		}

		if l2 != nil {
			flag += l2.Val
			l2 = l2.Next
		}
		list.Next = &ListNode{flag % 10, nil}
		flag /= 10
		list = list.Next
	}
	return res.Next
}
