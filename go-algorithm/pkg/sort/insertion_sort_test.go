package sort

import (
	"testing"

	"github.com/stretchr/testify/assert"
	"golang.org/x/exp/constraints"
)

func Test_insertionSort(t *testing.T) {
	type args[T constraints.Integer] struct {
		arr []T
	}
	type testCase[T constraints.Integer] struct {
		name string
		args args[T]
		want []T
	}
	tests := []testCase[int]{
		{
			name: "Integer Case",
			args: args[int]{
				arr: []int{31, 64, 49, 85, 71, 26, 6, 19},
			},
			want: []int{6, 19, 26, 31, 49, 64, 71, 85},
		},
		{
			name: "Empty array input",
			args: args[int]{},
			want: nil,
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			InsertionSort(tt.args.arr)

			assert.Equalf(t, tt.want, tt.args.arr, "InsertionSort() got = %v, want %v", tt.args.arr, tt.want)
		})
	}
}
