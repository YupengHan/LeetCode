class Solution {
public:
    static bool comp(pair<vector<int>, int> a, pair<vector<int>, int> b) {
        return a.second <= b.second;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<vector<int>, int>> vp;
        for (auto p:points) {
            int sum = 0;
            for (auto i:p) {
                sum += i*i;
            }
            vp.insert(vp.end(), make_pair(p, sum));
        }

        sort(vp.begin(), vp.end(), comp);

        vector<vector<int>> ret;
        for (int i = 0; i < K; i++) {
            ret.insert(ret.end(), vp[i].first);
        }
        return ret;

    }
    
};