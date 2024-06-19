package math

// GCDEuclidean finds the greatest common divisor of two numbers with Euclidean algorithm.
// The `a` is the dividend and `b` is the divisor.
func GCDEuclidean(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

// GCDEuclideanExtended finds the greatest common divisor of two numbers with extended Euclidean algorithm.
// The `a` is the dividend and `b` is the divisor.
func GCDEuclideanExtended(a, b int) (int, int, int) {
	if b == 0 {
		return a, 1, 0
	}
	d, x, y := GCDEuclideanExtended(b, a%b)
	return d, y, x - (a/b)*y
}
