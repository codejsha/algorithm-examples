package sort

import (
	"golang.org/x/exp/constraints"
)

func bubbleSort[T constraints.Integer](arr []T) {
	n := len(arr)
	for i := 0; i < n; i++ {
		for j := n - 1; j > i; j-- {
			if arr[j] < arr[j-1] {
				arr[j], arr[j-1] = arr[j-1], arr[j]
			}
		}
	}
}
