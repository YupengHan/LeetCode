/*
    Similar to 1143, construct the dp
    dp[i][j] = minimum number of change (word1[0:i], word2[0:j])
*/



class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        for (int i = 0; i < n+1; ++i) {
            dp[0][i] = i;
        }
        for (int i = 0; i < m+1; ++i) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i-1] != word2[j-1]) {
                    int cnum = min(dp[i-1][j-1] + 1, dp[i-1][j]+1);
                    cnum = min(cnum, dp[i][j-1]+1);
                    dp[i][j] = cnum;
                }
                else {
                    int cnum = min(dp[i-1][j-1], dp[i-1][j]+1);
                    cnum = min(cnum, dp[i][j-1]+1);
                    dp[i][j] = cnum;   
                }
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }
        
        return dp[m][n];
    }
};