// O(n), O(n)
func climbStairs(n int) int { 
	if n == 1 {
		return 1
	}

	dp := make([]int, n+1)
	dp[1] = 1
	dp[2] = 2
	for i := 3; i <= n; i++ {
		dp[i] = dp[i-1] + dp[i-2]
	}
	return tmp
}

// O(n), O(1)
func climbStairs2(n int) int {
	if n == 1 {
		return 1
	}
	a, b := 1, 2
	for i := 3; i <= n; i++ {
		sum := a + b
		a = b
		b = sum
	}
	return b
}
