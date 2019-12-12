#!/usr/bin/env python
# coding=utf-8

class Solution(object):
    def reverse(self, head):
        cur = None
        while head:
            next = head.next
            head.next = cur
            cur = head
            head = next
        return cur
