class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for (int i = 1; i < n+1; ++i) {
            if (p[i-1] == '*' && i > 1) {
                dp[0][i] = dp[0][i] || dp[0][i-2];
            }
        }
        dp[0][0] = true;
        // for (int i = 1; i < m+1; ++i) {
        //     if ()
        // }
        // for (int i = 1; i < m+1; ++i) {
        //     dp[0][i] = false;
        // }
        dp[0][0] = true;
        // cout << dp[0][2] << endl;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i-1] == p[j-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j-1] == '*') {
                    if (s[i-1] == p[j-2] || p[j-2] == '.') {
                        dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
                        if (j>1) {
                            dp[i][j] = dp[i][j] || dp[i][j-2];
                        }
                    }
                    else {
                        if (j>1) {
                            dp[i][j] = dp[i][j] || dp[i][j-2];
                        }
                        // dp[i][j] = 0;
                    }
                }
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }
        // for (int i = 0; i <= m; ++i) {
        //     for (int j = 0; j <= n; ++j) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }        

        return dp[m][n];

    }
};