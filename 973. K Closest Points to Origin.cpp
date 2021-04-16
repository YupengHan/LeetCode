class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        unordered_map<int, int> mMap;
        vector<int> SqVec;
        for (int i = 0; i < points.size(); ++i) {
            int sq = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            mMap.emplace(sq, i);
            SqVec.push_back(sq);
        }
        sort(SqVec.begin(), SqVec.end());
        for (auto n:SqVec) {
            cout << n << " ";
        }
        cout <<endl;
        // int idx = mMap[SqVec[k-1]];
        vector<vector<int>> ret;
        int l = k-1;
        int r = k-1;
        while(l-1 >= 0 && SqVec[l] == SqVec[l-1]) {
            l--;
        }
        while(r+1 < points.size() && SqVec[r] == SqVec[r+1]) {
            r++;
        }
        cout << l << " " << r << endl;
        
        for (int i = l; i <= r; ++i) {
            int idx = mMap[SqVec[i]];
            ret.push_back({points[idx][0], points[idx][1]});
        }
        return ret;
        // return {points[idx][0], points[idx][1]};
    }
};