package main

import (
	"fmt"
	"math/rand"
	"time"
)

func generateRandomVector(len, max, min int) (vet []int) {
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < len; i++ {
		vet = append(vet, rand.Intn(max-min+1)+min)
	}
	return
}

func solidezOne(A []int, p, r int) int {
	x := A[r]
	for q := r - 1; q >= p; q-- {
		s := 0
		for j := q; j < r; j++ {
			s = s + A[j]
			if s > x {
				x = s
			}
		}
	}
	return x
}

func maxofthree(a, b, c int) int {
	if a >= b && a >= c {
		return a
	}
	if b > c {
		return b
	}
	return c
}

func solidezTwo(A []int, p, r int) int {
	if p == r {
		return A[p]
	}
	var q = int(p+r) / 2
	x1 := solidezTwo(A, p, q)
	x2 := solidezTwo(A, q+1, r)
	y1 := A[q]
	s := y1
	for i := q - 1; i >= p; i-- {
		s = s + A[i]
		if s > y1 {
			y1 = s
		}
	}
	y2 := A[q+1]
	s = y2
	for i := q + 2; i < r; i++ {
		s = s + A[i]
		if s > y2 {
			y2 = s
		}
	}
	x := maxofthree(x1, y1+y2, x2)
	return x
}

func solidezthree(A []int, p, r int) int {
	F := make([]int, len(A))
	F[p] = A[p]
	x := F[p]
	for q := p + 1; q <= r; q++ {
		s := F[q-1] + A[q]
		if s > A[q] {
			F[q] = s
		} else {
			F[q] = A[q]
		}
	}
	for q := p + 1; q <= r; q++ {
		if F[q] > x {
			x = F[q]
		}
	}
	return x
}

func solidezthreeModify(A []int, p, r int) int {
	F := A[p]
	x := F
	for q := p + 1; q <= r; q++ {
		s := F + A[q]
		if s > A[q] {
			F = s
		} else {
			F = A[q]
		}
		if F > x {
			x = F
		}
	}
	return x
}

func main() {
	var lens = []int{100, 1000, 10000, 100000, 1000000}
	for _, v := range lens {
		vet := generateRandomVector(v, 1000, -1000)
		startI := time.Now()
		solidezOne(vet, 0, len(vet)-1)
		durationI := time.Since(startI)
		fmt.Println("SolidezI: ", durationI, " qnt:", v)
		vet = generateRandomVector(v, 1000, -1000)

		startII := time.Now()
		solidezTwo(vet, 0, len(vet)-1)
		durationII := time.Since(startII)
		fmt.Println("SolidezII: ", durationII, " qnt:", v)
		vet = generateRandomVector(v, 1000, -1000)
		startIII := time.Now()
		solidezthree(vet, 0, len(vet)-1)
		durationIII := time.Since(startIII)

		fmt.Println("SolidezIII: ", durationIII, " qnt:", v)
	}
}
