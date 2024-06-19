package math

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestGCDEuclidean(t *testing.T) {
	assert.Equal(t, 12, GCDEuclidean(24, 36))
	assert.Equal(t, 1, GCDEuclidean(17, 22))
	assert.Equal(t, 20, GCDEuclidean(120, 500))
}

func TestGCDEuclideanExtended(t *testing.T) {
	d1, _, _ := GCDEuclideanExtended(24, 36)
	assert.Equal(t, 12, d1)
	d2, _, _ := GCDEuclideanExtended(17, 22)
	assert.Equal(t, 1, d2)
	d3, _, _ := GCDEuclideanExtended(120, 500)
	assert.Equal(t, 20, d3)
}
