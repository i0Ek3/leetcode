#!/usr/bin/env python3

class Solution(object):
    def maxSubArray(self, nums):
        for i in range(1, len(nums)):
            nums[i] += max(nums[i-1], 0)
        return max(nums)

