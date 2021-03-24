class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> buy(n, INT_MIN), sell(n, 0);
        buy[0] = -prices[0]-fee;
        sell[0] = 0;

        for (int i = 1; i < n; ++i) {
            buy[i] = max(buy[i-1], sell[i-1]-prices[i]-fee);
            sell[i] = max(sell[i-1], buy[i-1]+prices[i]);
        }
        return max(buy[n-1], sell[n-1]);
    }
};