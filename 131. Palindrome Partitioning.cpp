class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        dfs(s, ans, cur, 0);
        return ans;
    }
    void dfs(string s, vector<vector<string>>& ans, vector<string>& cur, int sIdx) {
        if (sIdx == s.size()) {
            ans.push_back(cur);
            return;
        }
        for (int i = 1; i <= s.size()-sIdx; ++i) {
            string curSub = s.substr(sIdx, i);
            if (isPalindrome(curSub)) {
                cur.push_back(curSub);
                cout << sIdx << " " << i << " " << curSub << " " << "curSubsize" << cur.size() << endl;
                
                dfs(s, ans, cur, sIdx + i);
                cur.pop_back();
            }
        }
    }

    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while(l<r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
}; 