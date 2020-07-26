func removeElement(nums []int, value int) int {
	for i := 0; i < len(nums); {
		if (nums[i] == value) {
			// 将后面的值覆盖前面的值
			nums = append(nums[:i], nums[i+1:]...)
		} else {
			i++
		}
	}
	return len(nums)
}
