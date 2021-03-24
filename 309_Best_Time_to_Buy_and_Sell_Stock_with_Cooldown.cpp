class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        vector<int> buy(days, 0);
        vector<int> sell(days, 0);
        vector<int> cd(days, 0);
        if (days < 2) return 0;
        if (days == 2) {
            if (prices[1] - prices[0] > 0 ) {
                return prices[1] - prices[0];   
            }
            return 0;
        }
        buy[0] = -prices[0], buy[1] = max(-prices[0], -prices[1]);
        sell[1] = buy[0]+prices[1];

        for (int i = 2; i < days; ++i) {
            buy[i]  = max(buy[i-1], cd[i-1]-prices[i]);
            sell[i] = buy[i-1]+prices[i];
            cd[i]   = sell[i-1];
            // cout << buy[i] << " " << sell[i] << " " << cd[i] << endl;
        }
        for (int i = 0; i < days; ++i) {
            cout << buy[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < days; ++i) {
            cout << sell[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < days; ++i) {
            cout << cd[i] << " ";
        }
        cout << endl;
        int ret = max(cd[days-1], sell[days-1]);
        ret = max(ret, buy[days-1]);
        return ret;
    }
};