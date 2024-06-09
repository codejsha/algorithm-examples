package math

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestGCD(t *testing.T) {
	assert.Equal(t, 12, GCD(24, 36))
	assert.Equal(t, 1, GCD(17, 22))
	assert.Equal(t, 20, GCD(120, 500))
}
