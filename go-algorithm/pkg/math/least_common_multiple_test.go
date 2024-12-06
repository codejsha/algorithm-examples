package math

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test_LCM(t *testing.T) {
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
			want: 72,
		},
		{
			name: "Case 2",
			args: args{
				a: 17,
				b: 22,
			},
			want: 374,
		},
		{
			name: "Case 3",
			args: args{
				a: 120,
				b: 500,
			},
			want: 3000,
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := LCM(tt.args.a, tt.args.b)

			assert.Equalf(t, tt.want, got, "LCM() got = %v, want %v", got, tt.want)
		})
	}
}
