func rotation(nums []int, k int) {
	reverse(nums)
	reverse(nums[:k % len(nums)])
	reverse(nums[k % len(nums):])
}

func reverse(nums []int) {
	// 不能遍历到整个数组长度是因为会有负值出现
	for i := 0; i < len(nums) / 2; i++ {
		nums[i], nums[len(nums)-i-1] = nums[len(nums)-i-1], nums[i]
	}
	
}
