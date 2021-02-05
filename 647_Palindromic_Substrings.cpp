class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); ++i) {
            dp[0][i] = 1;
            dp[1][i] = 1;
        }
        for (int i = 2; i <= s.size(); ++i) {
            for (int j = 0; j+i <= s.size(); ++j) {
                if (s[j] == s[j+i-1]) {
                    dp[i][j] = dp[i-2][j+1];
                }
            }    
        }
        int cnt = 0;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j+i <= s.size(); ++j) {
                cnt += dp[i][j];
            }
            
        }
        return cnt;
    }
};