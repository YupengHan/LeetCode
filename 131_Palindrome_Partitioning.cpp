class Solution {
private:
    void bt(string s, vector<vector<int>>& dp, vector<vector<string>>& ret, vector<string>& cur, int ori_len) {
        if (s.size() == 0) {
            ret.push_back(cur);
            return;
        }
        for (int i = 1; i <= s.size(); ++i) {
            int dpstart = ori_len - s.size();
            if(dp[i][dpstart]) {
                cur.push_back(s.substr(0,i));
                bt(s.substr(i,s.size()-i), dp, ret, cur, ori_len);
                cur.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); ++i) {
            dp[0][i] = 1;
            dp[1][i] = 1;
        }
        for (int i = 2; i <= s.size(); ++i) {
            for (int j = 0; j+i <= s.size(); ++j) {
                if (s[j] == s[j+i-1]) {
                    dp[i][j] = dp[i-2][j+1];
                }
            }    
        }
        vector<vector<string>> ret;
        vector<string> cur;
        bt(s, dp, ret, cur, s.size());
        return ret;
    }
};