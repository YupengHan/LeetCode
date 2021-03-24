// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
        
//         int pn = prices.size();
//         if (pn == 0) return 0;
//         vector<vector<int>> dp(k+1, vector<int> (pn, 0));
//         int buy = INT_MIN;
//         int sell = 0;
//         for (int i = 0; i < pn; ++i) {
//             buy = max(buy, -prices[i]);
//             sell = max(sell, buy+prices[i]);
//             dp[1][i] = sell;
//         }
//         for (int i = 2; i <= k; ++i) {
//             for (int j = 1; j < pn; ++j) {
//                 if (prices[j] > prices[j-1]) {
//                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//                     dp[i][j] = max(dp[i][j], dp[i-1][j-1] + prices[j]-prices[j-1]);
//                 }
//                 else {
//                     dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//                 }
//             }
//         }
//         for (int i = 0; i <= k; ++i) {
//             for (int j = 0; j < pn; ++j) {
//                 cout << dp[i][j] << " ";
//             }
//             cout << endl;
//         }
//         return dp[k][pn-1];
//     }
// };

/*
    两个二维dp
    如果 k 大约总天数，那么我们一旦发现可以赚钱就进行买卖。
    如果 k 小于总天数：
        我们可以 建立两个动态规划数组 buy 和 sell，对于每天的股票价格，
        buy[j] 表示在第 j 次买入时的最大收益，
        sell[j] 表示在第 j 次卖出时的最大收益。

        所以我上一个写法的问题是， 没能考虑到记录卖出时机！

        i:day
        j:交易次数

        每一天只有两种状态：
            买入或者卖出

        buy[i][j] = max( buy[i-1][j], sell[i-1][j-1] - prices[i] )
*/



class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int days = prices.size();
        if (days < 2) {
            return 0;
        }

        if (k >= days) {
            int ret = 0;
            for (int i = 1; i < prices.size(); ++i) {
                if (prices[i] > prices[i-1]) {
                    ret += prices[i] - prices[i-1];
                }
            }
            return ret;
        }

        vector<int> buy_day_prof(k+1, INT_MIN);
        vector<int> sell_day_prof(k+1, 0);
        for (int i = 0; i < days; ++i) {
            for (int j = 1; j <= k; ++j) {
                buy_day_prof[j] = max(buy_day_prof[j], sell_day_prof[j-1] - prices[i]);
                sell_day_prof[j] = max(sell_day_prof[j], buy_day_prof[j] + prices[i]);
            }
        }
        
        return sell_day_prof[k];
    }
};
















































