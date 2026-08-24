package sort

import (
	"math"

	"golang.org/x/exp/constraints"
)

func BucketSort[T constraints.Integer](arr []T) []T {
	n := len(arr)

	var maxVal, minVal T
	for _, v := range arr {
		if v > maxVal {
			maxVal = v
		}
		if v < minVal {
			minVal = v
		}
	}
	rangeVal := maxVal - minVal

	bucket := make([][]T, n)
	for i := 0; i < n; i++ {
		bucket[i] = make([]T, 0)
	}

	for _, v := range arr {
		index := int(math.Floor(float64(n) * float64((v-minVal)/rangeVal)))
		if index == n {
			index--
		}
		bucket[index] = append(bucket[index], v)
	}

	for i := 0; i < n; i++ {
		InsertionSort(bucket[i])
	}

	sorted := make([]T, 0, n)
	for i := 0; i < n; i++ {
		sorted = append(sorted, bucket[i]...)
	}

	return sorted
}
