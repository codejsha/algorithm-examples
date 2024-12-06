package math

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_GCDEuclidean(t *testing.T) {
	type args struct {
		a int
		b int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			name: "Case 1",
			args: args{
				a: 24,
				b: 36,
			},
			want: 12,
		},
		{
			name: "Case 2",
			args: args{
				a: 17,
				b: 22,
			},
			want: 1,
		},
		{
			name: "Case 3",
			args: args{
				a: 120,
				b: 500,
			},
			want: 20,
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := GCDEuclidean(tt.args.a, tt.args.b)

			assert.Equalf(t, tt.want, got, "GCDEuclidean(%v, %v)", tt.args.a, tt.args.b)
		})
	}
}

func Test_GCDEuclideanExtended(t *testing.T) {
	type args struct {
		a int
		b int
	}
	tests := []struct {
		name string
		args args
		want int
	}{
		{
			name: "Case 1",
			args: args{
				a: 24,
				b: 36,
			},
			want: 12,
		},
		{
			name: "Case 2",
			args: args{
				a: 17,
				b: 22,
			},
			want: 1,
		},
		{
			name: "Case 3",
			args: args{
				a: 120,
				b: 500,
			},
			want: 20,
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got, _, _ := GCDEuclideanExtended(tt.args.a, tt.args.b)

			assert.Equalf(t, tt.want, got, "GCDEuclideanExtended(%v, %v)", tt.args.a, tt.args.b)
		})
	}
}
