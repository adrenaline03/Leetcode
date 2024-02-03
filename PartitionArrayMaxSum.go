var dp [510]int

func solve(i, k int, arr []int) int {
	if i == len(arr) {
		return 0
	}
	if dp[i] != -1 {
		return dp[i]
	}
	ans := 0
	mx := 0
	for j := i; j < i+k && j < len(arr); j++ {
		mx = int(math.Max(float64(mx), float64(arr[j])))
		ans = int(math.Max(float64(ans), float64(mx)*(float64(j-i+1))+float64(solve(j+1, k, arr))))
	}
	dp[i] = ans
	return ans
}

func maxSumAfterPartitioning(arr []int, k int) int {
	for i := range dp {
		dp[i] = -1
	}
	return solve(0, k, arr)
}
