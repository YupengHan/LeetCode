class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<pair<int,int>> itvs(26, make_pair(-1,-1));
        for (int i = 0; i < S.size(); ++i) {
            int c_int = S[i]-'a';
            if (itvs[c_int].first == -1) {
                itvs[c_int].first = i;
            }
            if (i > itvs[c_int].second) {
                itvs[c_int].second = i;
            }
        }

        int cur_end = -1;
        vector<int> ret;
        for (int i = 0; i < S.size(); ++i) {
            if (i <= cur_end) {
                cur_end = max(cur_end, itvs[S[i]-'a'].second);
                ret[ret.size()-1] = ret[ret.size()-1]+1;
                // cout << S[i];
            }
            else {
                // cout << endl;
                // cout << S[i];
                ret.push_back(1);
                cur_end = itvs[S[i]-'a'].second;
            }
        }
        // ret.push_back(S.size());
        return ret;
    }
};