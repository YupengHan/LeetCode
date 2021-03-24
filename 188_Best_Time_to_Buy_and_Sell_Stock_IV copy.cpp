class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int days = prices.size();
        if (days < 2) {
            return 0;
        }
        if (k > days) {
            int ret = 0;
            for (int i = 1; i < days; ++i) {
                ret += max(prices[i] - prices[i-1], 0);
            }
            return ret;
        }

        // 这是一道二维的题目（答案利用空间压缩写了）
        buydp[i][j] 第i天，完成 购买 第j次最佳金钱（buydp是一个可出售的状态（sharehold == 1））
        seldp[i][j] 第i天，完成 出售 第j次最佳金钱（buydp是一个可购买的状态（sharehold == 0））


    }
};



// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         int days = prices.size();
//         if (days < 2) {
//             return 0;
//         }

//         if (k >= days) {
//             int ret = 0;
//             for (int i = 1; i < prices.size(); ++i) {
//                 if (prices[i] > prices[i-1]) {
//                     ret += prices[i] - prices[i-1];
//                 }
//             }
//             return ret;
//         }

//         vector<int> buy_day_prof(k+1, INT_MIN);
//         vector<int> sell_day_prof(k+1, 0);
//         for (int i = 0; i < days; ++i) {
//             for (int j = 1; j <= k; ++j) {
//                 buy_day_prof[j] = max(buy_day_prof[j], sell_day_prof[j-1] - prices[i]);
//                 cout << "b["<<j<<"] " <<buy_day_prof[j] << endl;
//                 sell_day_prof[j] = max(sell_day_prof[j], buy_day_prof[j] + prices[i]);
//                 cout << "s["<<j<<"] " <<sell_day_prof[j] << endl;
//             }
//         }
        
//         return sell_day_prof[k];
//     }
// };
