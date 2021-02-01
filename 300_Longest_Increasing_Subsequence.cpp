class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ns = nums.size();
        vector<int> dp(ns+1, 0);
        if (ns == 0) return 0;
        int max_size = 1;
        dp[1] = 1;
        for (int i = 2; i <= ns; ++i) {
            for (int j = i-1; j > 0; j--) {
                if (nums[i-1] > nums[j-1]) {
                    dp[i] = max(dp[i], dp[j]+1);
                    max_size = max(max_size, dp[i]);
                    // break;
                }
            }
            if (dp[i] == 0) {
                dp[i] = 1;   
            }
        }
        // for (int i = 1; i < ns+1; ++i) {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        return max_size;
    }
};