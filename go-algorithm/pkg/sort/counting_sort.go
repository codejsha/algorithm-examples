package sort

import (
	"golang.org/x/exp/constraints"
)

func CountingSort[T constraints.Integer](arr []T) []T {
	n := len(arr)
	output := make([]T, n)

	var maxVal T
	for _, v := range arr {
		if v > maxVal {
			maxVal = v
		}
	}

	// initialize count array
	count := make([]int, maxVal+1)

	// store the count of each element
	for i := 0; i < n; i++ {
		count[arr[i]]++
	}

	// store the cumulative count of each element
	for i := 1; i <= int(maxVal); i++ {
		count[i] += count[i-1]
	}

	// build the output array
	for i := n - 1; i >= 0; i-- {
		output[count[arr[i]]-1] = arr[i]
		count[arr[i]]--
	}

	return output
}
