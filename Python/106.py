#!/usr/bin/env python
# coding=utf-8

class Solution(object):
    def buildTree(self, inorder, post):
        if not inorder:
            return None
        x = post.pop()
        i = inorder.index(x)

        node = TreeNode(x)
        node.left = self.buildTree(inorder[:i], post[:i])
        node.right = self.buildTree(inorder[i+1:], post[i:])

        return node
