class Solution {
public:
    int integerBreak(int n) {
        vector<int> starter = {0, 0, 1, 2, 4};
        if (n <= 4) return starter[n];
        vector<int> dp(n+1, 1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; ++i) {
            dp[i] = max(1*dp[i-1], 2*dp[i-2]);
            dp[i] = max(dp[i], 3*dp[i-3]);
            cout << i << " " << dp[i] << endl;
        }
        return dp[n];
    }
};