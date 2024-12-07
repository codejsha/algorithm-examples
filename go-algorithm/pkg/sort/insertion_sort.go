package sort

import (
	"golang.org/x/exp/constraints"
)

func InsertionSort[T constraints.Integer](arr []T) {
	for i := 0; i < len(arr); i++ {
		key := arr[i]
		j := i - 1
		for j >= 0 && arr[j] > key {
			arr[j+1] = arr[j]
			j--
		}
		arr[j+1] = key
	}
}
