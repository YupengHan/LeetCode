class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, 0);
        // dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = i;
            int search_range = sqrt(i)+1;
            for (int j = 2; j < search_range; ++j) {
                if (i%j == 0) {
                    dp[i] = dp[i/j] + dp[j];
                    break;
                }
            }

        }
        // dp[1] = 0;
        return dp[n];
    }
};