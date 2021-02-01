/*
    我在比赛的时候是超时的算法
    要注意到palindrom内在的传递形式
    dp[i][j] 代表substring(s[i:j]) 是否palindrom
    if (s[i] == s[j]) {
        dp[i][j] == dp[i+1][j-1]
    }
    else {
        dp[i][j] = fasle;
    }

    在注意到dp[i][j]的格式，迭代的话，i从大到小！
*/

class Solution {
public:
    bool checkPartitioning(string s) {
        vector<vector<bool>> dppalindorm(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size()-1; i >= 0; i--) {
            for (int j = i; j < s.size(); ++j) {
                if (s[i] == s[j]) {
                    if (i+1 <= j-1) {
                        dppalindorm[i][j] = dppalindorm[i+1][j-1];
                    }
                    else {
                        dppalindorm[i][j] = true;
                    }
                }
                else {
                    dppalindorm[i][j] = false;
                }
            }
        }

        for (int i = 1; i < s.size()-1; ++i) {
            for (int j = i; j < s.size()-1; ++j) {
                if (dppalindorm[0][i - 1] && dppalindorm[i][j] && dppalindorm[j + 1][s.size() - 1]) return true;
            }
        }
        return false;
    }
};