func findLeastNumOfUniqueInts(arr []int, k int) int {
    m := map[int]int{}
    count := 0

    for _, i := range arr {
        m[i]++
    }

    freq := []int{}
    for _, i := range m {
        freq = append(freq, i)
    }

    sort.Ints(freq)

    for i := 0; i < len(freq); i++ {
        count += freq[i]

        if count > k {
            return len(freq) - i
        }
    }

    return 0
}