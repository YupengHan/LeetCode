class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) return 0;
        if (s[0] == '0') return 0;
        if (s.size() == 1) {
            return 1;
        }
        int n = s.size();
        vector<int> dp(n+1, 0);

        // for (int i = 1; i < n; ++i) {
        //     if (s[i] == '0' && s[i-1] == '0') return 0;
        // }
        
        dp[0] = 1;
        dp[1] = 1;
        // if (s[0]-'0' > 0 && s[0]-'0' < 10) {
        //     dp[1] = 1;
        // }
        // else {
        //     dp[1] = 0;
        // }
        

        unordered_set<string> dset{"10", "11", "12", "13", "14",
                                    "15", "16", "17", "18", "19",
                                    "20", "21", "22", "23", "24", "25", "26"};
        for (int i = 2; i <= n; ++i) {
            if (s[i-1] == '0'){
                string ahtwo = s.substr(i-2, 2);
                if (dset.find(ahtwo) == dset.end()) return 0;
                dp[i] = dp[i-2];
            }
            else {
                string ahtwo = s.substr(i-2, 2);

                if (dset.find(ahtwo) != dset.end()) {
                    dp[i] = dp[i-1] + dp[i-2];
                }
                else {
                    dp[i] = dp[i-1];    
                }
            }
            
        }
        return dp[n];

    }
};