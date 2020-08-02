func deleteNode(root * TreeNode, val int) *TreeNode {
	if root == nil {
		return nil 
	}

	if root.Val == val {
		if root.Left == nil && root.Right == nil {
			return nil
		} else if root.Left == nil {
			return root.Right
		} else if root.Right == nil {
			return root.Left
		} else {
			max := findMax(root.Left, val)
			root.Val = max
            root.Left = deleteNode(root.Left, max)
		}
	} else if root.Val > val {
		root.Left = deleteNode(root.Left, val)
	} else {
		root.Right = deleteNode(root.Right, val)
	}
	return root
}

func findMax(root *TreeNode) int {
	if root.Right == nil {
		return root.Val
	}
	return findMax(root.Right)
}
