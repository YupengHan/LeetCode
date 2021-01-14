class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // int max_expand = 1e6;
        vector<vector<int>> dp(K+2, vector<int>(n, 1e6));
        dp[0][src] = 0;

        for (int i = 1; i <= K+1; ++i) {
            dp[i][src] = 0;
            for (const auto& p : flights) {
                dp[i][p[1]] = min(dp[i][p[1]], dp[i-1][p[0]] + p[2]);
            }
        }

        return dp[K+1][dst] >= 1e6 ? -1 : dp[K+1][dst];
    }
};


// Bellman-Ford's Algorithm ??
    // Single source multiple defination 
    // min path
    // 滚动数组
    // emplace_block什么意思