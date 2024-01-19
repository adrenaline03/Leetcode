class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> dp(col, vector<int>(row, 0));
        
        for(int i = 0; i < row; i++) {
            dp[0][i] = matrix[0][i];
        }

        for(int i = 1; i < row; i++) {
            for(int j = 0; j < col; j++) {
                int ld = 1e9; 
                int rd = 1e9;
                int up = matrix[i][j] + dp[i-1][j];

                if(j - 1 >= 0) {
                    ld = matrix[i][j] + dp[i-1][j-1];
                }

                if(j + 1 < row) {
                    rd = matrix[i][j] + dp[i-1][j+1];
                }

                dp[i][j] = min(up, min(ld, rd));
            }
        }

        int mini = dp[col-1][0];

        for(int i = 1; i < row; i++) {
            mini = min(mini, dp[col-1][i]);
        }

        return mini;
    }
};