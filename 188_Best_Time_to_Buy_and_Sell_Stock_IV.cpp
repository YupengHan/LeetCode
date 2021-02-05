class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int pn = prices.size();
        if (pn == 0) return 0;
        vector<vector<int>> dp(k+1, vector<int> (pn, 0));
        int buy = INT_MIN;
        int sell = 0;
        for (int i = 0; i < pn; ++i) {
            buy = max(buy, -prices[i]);
            sell = max(sell, buy+prices[i]);
            dp[1][i] = sell;
        }
        for (int i = 2; i <= k; ++i) {
            for (int j = 1; j < pn; ++j) {
                if (prices[j] > prices[j-1]) {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + prices[j]-prices[j-1]);
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        for (int i = 0; i <= k; ++i) {
            for (int j = 0; j < pn; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[k][pn-1];
    }
};