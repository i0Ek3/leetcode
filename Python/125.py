#!/usr/bin/env python
# coding=utf-8

class Solution:
    def isPalinedrome(self, s: str) -> bool:
        s = list(filter(str.isalnum, s.lower()))
        return s == s[::-1]
