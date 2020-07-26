func plusOne(nums []int) []int {
	var ret []int
	flag := 0

	for i := len(nums)-1; i >= 0; i-- {
		nums[i] += flag
		flag = 0
		if i == len(nums)-1 {
			nums[i]++
		}
		if nums[i] == 10 {
			flag = 1
			nums[i] %= 10
		}
	}

	if flag == 1 {
		ret = make([]int, 1)
		ret[0] = 1
		ret = append(ret, nums...)
	} else {
		ret = nums
	}
	
	return ret

	// 下面的情况不用考虑，因为只是加1，所以不会有进位大于2并且余位大于0的情况
	//if nums[i] + 1 < 10 {
	//	nums[i] += 1
	//} else {
	//	flag := (nums[i]+1) / 10 
	//	rem := (nums[i]+1) % 10 
	//	nums[i] = rem
	//}
}
