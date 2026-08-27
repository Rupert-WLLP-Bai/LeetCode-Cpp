package main

func shortestBeautifulSubstring(s string, k int) string {
	count_one := 0
	for _, v := range s {
		if v == '1' {
			count_one++
		}
	}
	if count_one < k {
		return ""
	}
	res := s
	cnt := 0
	l := 0
	for r := 0; r < len(s); r++ {
		cnt += int(s[r] - '0')

		for cnt > k || s[l] == '0' {
			cnt -= int(s[l] - '0')
			l++
		}
		if cnt == k {
			t := s[l : r+1]
			if len(t) < len(res) || len(t) == len(res) && t < res {
				res = t
			}
		}
	}
	return res
}
