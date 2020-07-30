func isPalindrome(s string) bool {
	s = strings.ToLow(s) // need to import strings lib
	i, j := 0, len(s)-1
	for i < j {
		for i < j && !isChar(s[i]) {
			i++
		}
		for i < j && !isChar(s[j]) {
			j--
		}
		if s[i] == s[j] {
			i++
			j--
		}
		return true
	}
	return false
}
