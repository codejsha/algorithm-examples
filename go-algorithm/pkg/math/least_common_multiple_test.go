package math

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestLCM(t *testing.T) {
	assert.Equal(t, 72, LCM(24, 36))
	assert.Equal(t, 374, LCM(17, 22))
	assert.Equal(t, 3000, LCM(120, 500))
}
