class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        // if (points.size() == 1) return 1;
        
        // sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) {return a[1] < b[1];});
        // sort(begin(points), end(points), [](const vector<int> &o1, const vector<int> &o2) {return (o1[1] < o2[1]);});
        sort(points.begin(), points.end(), [](const vector<int> &o1, const vector<int> &o2) {return (o1[1] < o2[1]);});
        /*
            这里很有趣，sorted lambda使用const 速度会快很多！
        */
        int shot_cnt = 1;
        int cur_end = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            // cout << points[i][0] << " " << cur_end << endl;
            if (points[i][0] > cur_end) {
                shot_cnt++;
                // cout << shot_cnt << endl;
                // cur_end = max(cur_end, points[i][1]);
                cur_end = points[i][1];
            }
        }
        // for (int i = 1; i < points.size(); ++i) {
        //     int xs = points[i][0];
        //     int xe = points[i][1];
        //     if (cur_end < xs) {
        //         shot_cnt++;
        //         cur_end = xe;
        //     }
        // }
        return shot_cnt;
    }
};