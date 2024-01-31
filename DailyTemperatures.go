func dailyTemperatures(temperatures []int) []int {
    n := len(temperatures)
    st := make([]int, 0)
    result := make([]int, n)

    for i := n - 1; i >= 0; i-- {
        for len(st) > 0 && temperatures[i] >= temperatures[st[len(st)-1]] {
            st = st[:len(st)-1]
        }

        if len(st) == 0 {
            result[i] = 0
        } else {
            result[i] = st[len(st)-1] - i
        }

        st = append(st, i)
    }

    return result 
}