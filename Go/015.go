func threeSum(nums []int) [][]int {
	ret := [][]int{}
	sort.Ints(nums)

	for i := 0; i < len(nums); i++ {
		if nums[i] > 0 {
			break
		}
		
		right, left := i+1, len(nums)-1
		for left < right {
			sum := 	nums[i] + nums[left] + nums[right]
		
			if sum > 0 {
				right--
			} else if sum < 0{
				left++
			} else {
				ret = append(ret, []int{nums[i], nums[left], nums[right]})
				right--
				left++
			}	
		}
	}
	return ret
}
