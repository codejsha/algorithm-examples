package math

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestGCD(t *testing.T) {
	assert.Equal(t, 12, NumberTuple{24, 36}.gcd())
	assert.Equal(t, 1, NumberTuple{17, 22}.gcd())
	assert.Equal(t, 20, NumberTuple{120, 500}.gcd())
}

func TestGCDExtended(t *testing.T) {
	d1, _, _ := NumberTuple{24, 36}.gcdExtended()
	assert.Equal(t, 12, d1)
	d2, _, _ := NumberTuple{17, 22}.gcdExtended()
	assert.Equal(t, 1, d2)
	d3, _, _ := NumberTuple{120, 500}.gcdExtended()
	assert.Equal(t, 20, d3)
}
