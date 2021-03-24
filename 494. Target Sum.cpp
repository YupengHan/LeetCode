//看到提示，这是一个01背包的问题



class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (S > 1000) return 0;
        /*
            dp[i][j], 使用前n个数字总和为j的所有可能之和
        */

        int m = nums.size();
        vector<vector<int>> dp(m+1, vector<int>(2001, 0));
        // encoding  dp[x][sum+1000]
        dp[0][1000] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = -1000; j <= 1000; ++j) {

                int item1 = 0;
                if ((j-nums[i-1]  +1000) >= 0 && (j-nums[i-1]  +1000) <= 2000) {
                    item1 = dp[i-1][j-nums[i-1]  +1000];
                }
                int item2 = 0;
                if ((j+nums[i-1]  +1000) >= 0 && (j+nums[i-1]+1000) <= 2000) {
                    item2 = dp[i-1][j+nums[i-1]  +1000];
                }
                
                dp[i][j+1000] = item1 + item2;
                if (dp[i][j+1000] != 0) {
                    // cout << item1 << " " << item2 << " ";
                    // cout << i << " " << j << " " << dp[i][j+1000] << endl;    
                }
                

            }
        }
        return dp[m][S+1000];
    }
};