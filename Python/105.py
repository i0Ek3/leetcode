#!/usr/bin/env python
# coding=utf-8

class Solution(object):
    def buildTree(self, pre, inorder):
        if not pre:
            return None

        x = pre.pop()
        i = inorder.index(x)

        node = TreeNode(x)
        node.left = self.buildTree(pre[:i], inorder[:i])
        node.right = self.buildTree(pre[i:], iorder[i+1:])

        return node
