package sort

import (
	"golang.org/x/exp/constraints"
)

func heapSort[T constraints.Integer](arr []T) {
	n := len(arr)
	_buildMaxHeap(arr)
	for i := n - 1; i > 0; i-- {
		arr[0], arr[i] = arr[i], arr[0]
		_maxHeapify(arr, 0, i)
	}
}

func _buildMaxHeap[T constraints.Integer](arr []T) {
	n := len(arr)
	for i := n/2 - 1; i >= 0; i-- {
		_maxHeapify(arr, i, n)
	}
}

func _maxHeapify[T constraints.Integer](arr []T, i, n int) {
	largest := i
	for {
		left := 2*i + 1
		right := 2*i + 2

		if left < n && arr[largest] < arr[left] {
			largest = left
		}
		if right < n && arr[largest] < arr[right] {
			largest = right
		}
		if largest == i {
			break
		}

		arr[i], arr[largest] = arr[largest], arr[i]
		i = largest
	}
}
