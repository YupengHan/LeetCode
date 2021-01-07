class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        unordered_map<int, int> dp;

        // Sort the intervals
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return a[1] < b[1];
        });

        for (auto interval : intervals) {
            dp[interval[1]] = 1;
        }


        int cnt = 0;
        for (auto interval : intervals) {
            int c_max;
            if (dp.count(interval[0])) c_max = dp[interval[0]] + 1;
            else c_max = cnt+1;
            for (int i = interval[0]; i < interval[1]; ++i) {
                if (dp.count(i)) {
                    c_max = max(c_max, dp[i]);    
                }
            }
            dp[interval[1]] = max(dp[interval[1]], c_max);
            cout << "dp["<< interval[1] <<"]" << dp[interval[1]] << endl;
            cnt = max(c_max, cnt);
        }
        return (intervals.size()-cnt);
    }
};

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) {return 0;}
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {return a[1] < b[1];});
    int total = 0, prev = intervals[0][1];
    for (int i = 1; i < n; ++i) {
        if (intervals[i][0] < prev) {
            ++total;
        } else {
            prev = intervals[i][1];
        }
    }
    return total;
}