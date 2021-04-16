// class Solution {
// public:
//     struct cmp {
//         bool operator()(const int &a, const int &b) {
//             return a > b;
//         }
//     };
//     int nthUglyNumber(int n) {
//         vector<int> muls = {2,3,5};
//         priority_queue<int, vector<int>, cmp> pq;
//         unordered_set<int> visited;
//         pq.push(1);
//         visited.insert(1);
//         for (int i = 1; i < n; ++i) {
//             int cNum = pq.top();
//             pq.pop();
//             for (auto mul:muls) {
//                 if (cNum < INT_MAX/mul) {
//                     int nNum = cNum*mul;
//                     if (!visited.count(nNum)) {
//                         pq.push(nNum);
//                         visited.insert(nNum);
//                     }    
//                 }
                
//             }
//         }
//         return pq.top();

//     }
// };


class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglys = {1};
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; ++i) {
            int prevNum = uglys[i-1];
            while (uglys[p2] * 2 <= prevNum) p2++;
            while (uglys[p3] * 3 <= prevNum) p3++;
            while (uglys[p5] * 5 <= prevNum) p5++;
            int cNum = min(uglys[p2] * 2, uglys[p3] * 3);
            cNum = min(cNum, uglys[p5] * 5);
            uglys.push_back(cNum);
        }

        // for (auto item : uglys) {
        //     cout << item << " ";
        // }
        // cout << endl;
        return uglys[n-1];

    }
};

















