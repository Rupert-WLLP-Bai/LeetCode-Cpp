package main

import (
	"sort"
	"strconv"
)

func maximumSwap(num int) int {
	origin := []byte(strconv.Itoa(num))

	// 复制一份用于降序排序
	sorted := make([]byte, len(origin))
	copy(sorted, origin)

	sort.Slice(sorted, func(i, j int) bool {
		return sorted[i] > sorted[j]
	})

	// 找第一个和降序结果不同的位置
	for i := range origin {
		if origin[i] != sorted[i] {

			// sorted[i] 是我们想换到当前位置的数字
			// 从右往左找，必须换最右边的那个
			for j := len(origin) - 1; j > i; j-- {
				if origin[j] == sorted[i] {
					origin[i], origin[j] = origin[j], origin[i]

					ans, _ := strconv.Atoi(string(origin))
					return ans
				}
			}
		}
	}

	return num
}
