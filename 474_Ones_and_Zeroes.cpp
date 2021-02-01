class Solution {
private:
    pair<int, int> cntstr(string s) {
        int c0 = 0, c1 = 0;
        for (auto cc : s) {
            if (cc == '0') {
                c0++;
            }
            else {
                c1++;
            }
        }
        return make_pair(c0, c1);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>>(m+1,vector<int>(n+1, 0)));
        for (int i = 1; i <= strs.size(); ++i) {
            auto [i0, i1] = cntstr(strs[i-1]);
            // cout << "-------------------" << endl;
            // cout << i0 << " " << i1 << endl;
            // cout << "-------------------" << endl;
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    if (j == 0 && k == 0) {
                        dp[i][j][k] = 0;
                        // continue;
                    }
                    else if (j == 0) {
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i][j][k-1]);
                        if (j >= i0 && k>=i1) {
                            dp[i][j][k] = (dp[i][j][k], dp[i-1][j-i0][k-i1] + 1);
                        }
                    }
                    else if (k == 0) {
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k]);
                        if (j >= i0 && k>=i1) {
                            dp[i][j][k] = (dp[i][j][k], dp[i-1][j-i0][k-i1] + 1);
                        }
                    }
                    else if (j>=i0 && k >= i1) {
                        int max1 = max(dp[i-1][j][k], dp[i-1][j-i0][k-i1]+1);
                        int max2 = max(dp[i][j-1][k], dp[i][j][k-1]);
                        dp[i][j][k] = max(max1, max2);
                        // continue;
                    }
                    else {
                        int max2 = max(dp[i][j-1][k], dp[i][j][k-1]);
                        dp[i][j][k] = max(dp[i-1][j][k], max2);
                        // continue;
                    }
                    // cout << dp[i][j][k] << " ";
                    
                }
                // cout << endl;
            }
        }
        return dp[strs.size()][m][n];
    }
};


/*
        i item, j "0", k "1",
    dp[i][j][k]
    int i0, i1;
    dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-i0][k-i1] + 1, dp[i][j-1][k], dp[i][j][k-1])
*/

