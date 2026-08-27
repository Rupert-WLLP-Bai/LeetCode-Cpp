package main

func missingMultiple(nums []int, k int) int {
	m := make(map[int]bool)

	for _, num := range nums {
		if num%k == 0 {
			m[num/k] = true
		}
	}

	for i := 1; ; i++ {
		if !m[i] {
			return i * k
		}
	}
}
