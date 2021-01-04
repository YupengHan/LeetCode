class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int s_child = 0;
        int cur_unsatified_child = 0;
        for (auto cur_cookie : s) {
            if (cur_cookie >= g[cur_unsatified_child]) {
                cur_unsatified_child++;
                s_child++;
                if (s_child >= g.size()) return g.size();
            }
        }

        return s_child;
        
    }
};