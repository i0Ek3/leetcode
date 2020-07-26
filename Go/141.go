func hasCircle(head *ListNode) bool {
	if head == nil {
		return false
	}

	fast := head.Next
	for fast != nil && head != nil && fast.Next != nil {
		fast = fast.Next.Next
		head = head.Next
		if fast == head {
			return true
		}
	}
	return false
}
