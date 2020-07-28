func maxSubArray(nums []int) int {
	n := len(nums)
	if n < 1 {
		return 0
	}
	dp := make([]int, n)
	res := nums[0]
	dp[0] = nums[0]
	for i := 1; i < n; i++ {
		dp[i] = max(nums[i], nums[i]+dp[i-1])
		res = max(dp[i], res)
	}
	return res
}

func maxSubArray2(nums []int) int {
	maxsum, res := nums[0], nums[0]
	for i := 1; i < n; i++ {
		res = max(res+nums[i], nums[i])
		maxsum = max(maxsum, res)
	}
	return maxsum
}
