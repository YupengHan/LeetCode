class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        int n = word.size();
        string cur = word;
        vector<string> ans;
        for (int i = 0; i <= n; ++i) {
            dfs(cur, ans, i, 0);
        }
        return ans;
    }
    void dfs(string cur, vector<string>& ans, int targetLen, int start) {
        if (targetLen == 0) {
            // cout << cur << endl;
            int csum = 0;
            string cstr;
            for (int i = 0; i < cur.size(); ++i) {
                if (cur[i] == '1') {
                    csum += 1;
                }
                else if (csum == 0){
                    cstr += cur[i];
                }
                else {
                    cstr += to_string(csum) + cur[i];
                    csum = 0;
                }

            }
            if (csum != 0) {
                cstr += to_string(csum);
                csum = 0;
            }
            ans.push_back(cstr);

            return;
        }
        for (int i = start; i < cur.size(); ++i) {
            string nstr = cur;
            nstr[i] = '1';
            dfs(nstr, ans, targetLen-1, i+1);
        }
    }
};