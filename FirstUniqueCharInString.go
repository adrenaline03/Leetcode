func firstUniqChar(s string) int {
    charArr := make([]int, 26)
    for _, char := range s {
        charArr[int(char - 'a')]++
    }
    for i, char := range s {
        if charArr[int(char - 'a')] == 1 {
            return i
        }
    }
    return -1
}