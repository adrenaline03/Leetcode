class Solution {
public:
    int mod = 1000000000 + 7;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int count = 0;
        dp[startRow][startColumn] = 1;

        for (int itr = 1; itr <= maxMove; itr++) {
            vector<vector<int>> temp(m, vector<int>(n, 0));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == m - 1)
                        count = (count + dp[i][j]) % mod;
                    if (j == n - 1)
                        count = (count + dp[i][j]) % mod;
                    if (i == 0)
                        count = (count + dp[i][j]) % mod;
                    if (j == 0)
                        count = (count + dp[i][j]) % mod;

                    temp[i][j] = (
                        ((i > 0 ? dp[i - 1][j] : 0) + (i < m - 1 ? dp[i + 1][j] : 0)) % mod +
                        ((j > 0 ? dp[i][j - 1] : 0) + (j < n - 1 ? dp[i][j + 1] : 0)) % mod
                    ) % mod;
                }
            }
            dp = temp;
        }
        return count;
    }
};