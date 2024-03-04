class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int l = 0;
        int h = tokens.size() - 1;
        int score = 0;

        sort(tokens.begin(), tokens.end());

        while(l <= h) {
            if (power >= tokens[l]) {
                score++;
                power -= tokens[l];
                l++;
            } else if (l < h && score > 0) {
                score--;
                power += tokens[h];
                h--;
            } else {
                return score;
            }
        }

        return score;
    }
};