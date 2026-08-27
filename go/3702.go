package main

func longestSubsequence(nums []int) int {
	xor := 0
	all_zero := 1
	for _, num := range nums {
		if num != 0 {
			all_zero = 0
		}
		xor ^= num
	}
	if all_zero == 1 {
		return 0
	}
	if xor != 0 {
		return len(nums)
	}
	return len(nums) - 1
}
