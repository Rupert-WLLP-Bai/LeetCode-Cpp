package main

func maxNumberOfFamilies(n int, reservedSeats [][]int) int {
	// 每一行用一个8bit来存储2~9的预定情况（col-2为下标）
	rowMap := make(map[int]int)
	for _, seat := range reservedSeats {
		row, col := seat[0], seat[1]
		if col >= 2 && col <= 9 {
			rowMap[row] |= 1 << (col - 2)
		}
	}

	rowWithReserve := len(rowMap)
	res := (n - rowWithReserve) * 2

	for _, mask := range rowMap {
		// [2,3,4,5], [6,7,8,9] , [4,5,6,7]
		blockL := mask & 0b00001111
		blockR := mask & 0b11110000
		blockM := mask & 0b00111100

		if blockL == 0 && blockR == 0 {
			// 左右
			res += 2
		} else if blockL == 0 || blockR == 0 || blockM == 0 {
			// 一边
			res += 1
		}
	}
	return res
}
