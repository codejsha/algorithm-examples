package math

// GCD returns the greatest common divisor of a(dividend) and b(divisor).
func GCD(a int, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
