package sort

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_bucketSortInteger(t *testing.T) {
	type args struct {
		arr []int
	}
	tests := []struct {
		name string
		args args
		want []int
	}{
		{
			name: "Integer Case",
			args: args{
				arr: []int{31, 64, 49, 85, 71, 26, 6, 19},
			},
			want: []int{6, 19, 26, 31, 49, 64, 71, 85},
		},
		{
			name: "Empty array input",
			args: args{
				arr: []int{},
			},
			want: []int{},
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := BucketSort(tt.args.arr)

			assert.Equalf(t, tt.want, got, "BucketSort() got = %v, want %v", got, tt.want)
		})
	}
}
