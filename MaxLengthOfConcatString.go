func hasDuplicate(s1 string, s2 string) bool {
    arr := make([]int, 26)

    for _, ch := range s1 {
        if arr[ch - 'a'] > 0 {
            return true
        } 
        arr[ch - 'a']++;
    }

    for _, ch := range s2 {
        if arr[ch - 'a'] > 0 {
            return true
        }
    }

    return false
}

func solve(idx int, arr []string, temp string, n int) int {
    if idx >= n {
        return len(temp)
    }

    take := 0
    notTake := 0

    if hasDuplicate(arr[idx], temp) {
        notTake = solve(idx + 1, arr, temp, n)
    } else {
        notTake = solve(idx+1, arr, temp, n)
        take = solve(idx+1, arr, temp+arr[idx], n)
    }

    return max(take, notTake)
}

func maxLength(arr []string) int {
    n := len(arr)
    temp := ""

    return solve(0, arr, temp, n)
}