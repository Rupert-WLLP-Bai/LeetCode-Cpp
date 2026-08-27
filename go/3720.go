package main

func lexGreaterPermutation(s string, target string) string {
	if len(s) != len(target) {
		return ""
	}
	count := make([]int, 300)
	for i := 0; i < len(s); i++ {
		count[s[i]]++
	}
	ans := make([]byte, len(s))

	// 回溯
	var dfs func(pos int, greater bool) bool
	dfs = func(pos int, greater bool) bool {
		if pos == len(s) {
			return greater
		}
		start := 0
		if !greater {
			start = int(target[pos])
		}
		for c := start; c < 300; c++ {
			if count[c] == 0 {
				continue
			}

			count[c]-- // 第一个最小的字符
			ans[pos] = byte(c)
			nextGreater := greater || byte(c) > target[pos]
			if dfs(pos+1, nextGreater) {
				return true
			}
			count[c]++
		}
		return false
	}

	if dfs(0, false) {
		return string(ans)
	}

	// 不存在
	return ""
}
