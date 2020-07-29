func (s []byte) int {
	m := make([]int, 26)
	for _, v := range s {
		m[v-'a']++
	}
	for i, k := range s {
		if m[k-'a'] == 1 {
			return i
		}
	}
	return -1
}
