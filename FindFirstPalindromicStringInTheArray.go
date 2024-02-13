func isPalindrome(s string) bool {
    i := 0
    j := len(s) - 1

    for i <= j {
        if s[i] == s[j] {
            i++
            j--
        } else {
            return false
        }
    }

    return true
}

func firstPalindrome(words []string) string {
    for i := 0; i < len(words) ; i++ {
        if isPalindrome(words[i]) {
            return words[i]
        }
    }

    return ""
}