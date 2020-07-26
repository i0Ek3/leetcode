func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}

	var b = []rune(s)
	res := make([]string, numRows)
	period := numRows * 2 - 2

	for i := range s {
		pos := i % period
		if pos < numRows {
			res[pos] += string(b[i])
		} else {
			res[period-pos] += string(b[i])
		}
	}
	return strings.Join(res, "")
}
