func bagOfTokensScore(tokens []int, power int) int {
    l := 0
    h := len(tokens) - 1
    score := 0

    sort.Ints(tokens)

    for l <= h {
        if power >= tokens[l] {
            score += 1
            power -= tokens[l]
            l += 1
        } else if l < h && score > 0 {
            score -= 1
            power += tokens[h]
            h -= 1
        } else {
            return score
        }
    }
    return score
}