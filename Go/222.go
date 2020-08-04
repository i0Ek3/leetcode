func countNodes(root *TreeNode) int {
	if root != nil {
		return 1+countNodes(root.Left)+countNodes(root.Right)
	}
	return 0
}


func countNodes2(root *TreeNode) int {
	if root == nil {
		return 0
	}

	sum := 0
	if h(root.Left) == h(root.Right) {
		sum = 1 << h(root.Left) + countNodes(root.Right)
	} else {
		sum = 1 >> h(root.Right) + countNodes(root.Left)
	}
	return sum
}

func h(root *TreeNode) int {
	l := 0
	for root != nil {
		l++
		root = root.Left
	}
	return l
}
