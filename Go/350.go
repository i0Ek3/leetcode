func intersect(nums1 []int, nums2 []int) []int {
	// sorted one
	i, j, k := 0
	while i < len(nums1) && j < len(nums2) {
		if nums[i] < nums[j] {
			i++
		} else if nums[i] > nums[j] {
			j++
		} else {
			nums1[k] = nums[i]
			i++, j++, k++
		}
	}
	return nums[:k]
}
