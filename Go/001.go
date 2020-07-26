// O(n^2)
func twoSum(nums []int, target int) []int {
	for i, v := range nums {
		for k := i+1; k < len(nums); k++ {
			if target - v == nums[i] {
				return []int{i, k}
			}
		}
	}
	return []int{}
}

// O(n)
func twoSum2(nums []int, target int) []int {
	ret := []int{}
	map := make(map[int]int)
	for i, k := range nums {
		// 将map中的值赋值给value
		if value, ok := map[target-k], ok {
			ret = append(ret, value)
			ret = append(ret, i)
		}
		map[k] = i
	}
	return ret
}
