func rotateString(a, b string) bool {
	return len(a) == len(b) && strings.Contains(a+a, b)
}
