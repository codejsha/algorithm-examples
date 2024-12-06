package sort

import (
	"testing"

	"github.com/stretchr/testify/assert"
	"golang.org/x/exp/constraints"
)

func Test_countingSort(t *testing.T) {
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
			want: []int{},
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := countingSort(tt.args.arr)

			assert.Equalf(t, tt.want, got, "countingSort() got = %v, want %v", got, tt.want)
		})
	}
}
