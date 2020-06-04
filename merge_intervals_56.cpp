/*
    超时算法
*/
// class Solution {
// public:
//     static bool comp(vector<int>& a, vector<int>& b) {
//         return a[0] < b[0];
//     }
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         if (intervals.empty()) return intervals;
//         sort(intervals.begin(), intervals.end(), comp);
//         for (int i = 0; i < intervals.size()-1; i++) {
//             // cout << i << " " << intervals.size() << endl;
//             if (intervals[i][1] >= intervals[i+1][0]) {
//                 // cout << "intervals[i][1]: " << intervals[i][1] << ";intervals[i+1][0]: " << intervals[i+1][0] << endl;
//                 vector<int> tmp = mg(intervals[i], intervals[i+1]);
//                 intervals.erase(intervals.begin()+i);
//                 intervals.erase(intervals.begin()+i);
//                 intervals.insert(intervals.begin()+i, tmp);
//                 i--;
//             }
//         }
//         return intervals;
//     }
//     vector<int> mg(vector<int> a, vector<int> b) {
//         a[1] = max(a[1], b[1]);
//         return a;
//     }
// };

class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return intervals;
        sort(intervals.begin(), intervals.end(), comp);
        
        for (int i = 0; i < intervals.size()-1; i++) {
            // cout << " ------------------ " << endl;
            // cout << i << " " << endl;
            int tl = intervals[i][0];
            int tr = intervals[i][1];
            int j = i;
            while (j+1 < intervals.size() && tr >= intervals[j+1][0]) {
                j++;
                cout << tr << " " << j << endl;
                tr = max(tr, intervals[j][1]);
            }
            // cout << "j:" << j << endl;
            intervals.erase(intervals.begin()+i, intervals.begin()+j+1);
            cout << intervals.size() << endl;
            intervals.insert(intervals.begin()+i, {tl, tr});
            // i--;
        }
        return intervals;
    }
};