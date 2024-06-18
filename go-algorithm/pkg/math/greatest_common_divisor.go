package math

type GCD interface {
	gcd(a int, b int) int
	gcdExtended(a int, b int) (int, int, int)
}

type NumberTuple struct {
	a int // dividend
	b int // divisor
}

// GCD finds the greatest common divisor of two numbers.
func (n NumberTuple) gcd() int {
	for n.b != 0 {
		n.a, n.b = n.b, n.a%n.b
	}
	return n.a
}

// GCDExtended finds the greatest common divisor of two numbers with extended Euclidean algorithm.
func (n NumberTuple) gcdExtended() (int, int, int) {
	if n.b == 0 {
		return n.a, 1, 0
	}
	d, x, y := NumberTuple{n.b, n.a % n.b}.gcdExtended()
	return d, y, x - (n.a/n.b)*y
}
