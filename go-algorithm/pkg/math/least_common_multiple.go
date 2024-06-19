package math

// LCM finds the least common multiple of two numbers.
// The `a` and `b` are the numbers.
func LCM(a, b int) int {
	return a * b / GCDEuclidean(a, b)
}
