class Solution {
public:
    int dp[510];
    int solve(int i, int k, vector<int>& arr) {
        if (i == arr.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int ans = 0;
        int mx = 0;
        for (int j = i; j < i + k && j < arr.size(); j++) {
            mx = max(mx, arr[j]);
            ans = max(ans, mx * (j - i + 1) + solve(j + 1, k, arr));
        }
        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, k, arr);
    }
};