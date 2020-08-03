func isBalanced(root *TreeNode) bool {
	if root == nil {
		return true
	}

	heightLeft := maxDepth(root.Left)+1
	heightRight := maxDepth(root.Right)+1

	if isBalanced(root.Left) && isBalanced(root.Right) && abs(heightLeft-heightRight) <= 1 {
		return true
	} 
	return false
}

func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	return max(maxDepth(root.Left), maxDepth(root.Right))+1
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func abs(a int) int {
	if a > 0 {
		return a 
	} 
	return -a
}
