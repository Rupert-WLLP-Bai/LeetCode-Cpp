package main

func stoneGameV(stoneValue []int) int {
	// 前缀和 区间dp
	// dp[l][r] 表示[l,r]区间内先手能获得的最大分数
	// 切分 [l,k] [k+1,r]
	// L = sum(l,k) R = sum(k+1,r)
	// 1. L<R: L+dp[l][k]
	// 2. L>R: R+dp[k+1][r]
	// 3. L=R: L+max(dp[l][k], dp[k+1][r])
	// 所有k中取最大值
	dp := make([][]int, len(stoneValue))
	for i := range dp {
		dp[i] = make([]int, len(stoneValue))
	}
	for i := 0; i < len(stoneValue); i++ {
		dp[i][i] = 0
	}
	prefixSum := make([]int, len(stoneValue)+1)
	for i := 1; i <= len(stoneValue); i++ {
		prefixSum[i] = prefixSum[i-1] + stoneValue[i-1]
	}
	for k := 1; k < len(stoneValue); k++ {
		for l := 0; l < len(stoneValue)-k; l++ {
			r := l + k
			maxVal := 0
			for m := l; m < r; m++ {
				L := prefixSum[m+1] - prefixSum[l]
				R := prefixSum[r+1] - prefixSum[m+1]
				if L < R {
					maxVal = max(maxVal, L+dp[l][m])
				} else if L > R {
					maxVal = max(maxVal, R+dp[m+1][r])
				} else {
					maxVal = max(maxVal, L+max(dp[l][m], dp[m+1][r]))
				}
			}
			dp[l][r] = maxVal
		}
	}
	return dp[0][len(stoneValue)-1]
}
