class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size()+1, vector<int> (s.size(), 0));
        for (int i = 0; i < s.size(); ++i) {
            dp[0][i] = 0;
            dp[1][i] = 1;
        }
        for (int i = 2; i <= s.size(); ++i) {
            for (int j = 0; j+i <= s.size(); ++j) {
                if (s[j] == s[j+i-1]) {
                    dp[i][j] = 2+dp[i-2][j+1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j+1]);
                }
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }
        return dp[s.size()][0];

    }
};