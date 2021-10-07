class myPair {
public:
    int x, y, val;
    myPair(int _x, int _y, int _val) {
        this->x = _x;
        this->y = _y;
        this->val = _val;
    }
};

// class myPairComp implements Comparator<myPair> {
// public:
//     int compare(myPair A, myPair B) {
//         return A.val - b.val;
//     }
// }

struct mycompare {
public:
    bool operator() (myPair& a, myPair& b) {
        return a.val > b.val;
    }
};


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};
        priority_queue<myPair, vector<myPair>, mycompare> minH;
        minH.push(myPair(0,0,matrix[0][0]));

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        for (int i = 0; i < k-1; ++i) {
            myPair cur = minH.top();
            minH.pop();
            for (int j = 0; j < 2; ++j) {
                int nextx = cur.x + dx[j];
                int nexty = cur.y + dy[j];
                if (nextx < m && nexty < n && !visited[nextx][nexty]) {
                    visited[nextx][nexty] = true;
                    printf("x: %d   y: %d   val: %d\n", nextx, nexty, matrix[nextx][nexty]);
                    minH.push(myPair(nextx, nexty, matrix[nextx][nexty]));
                }
            }
        }
        // cout << "------" << endl;
        // while (!minH.empty()) {
        //     printf("x: %d   y: %d   val: %d\n", minH.top().x, minH.top().y, minH.top().val);
        //     minH.pop();
        // }
        
        
        // printf("x: %d   y: %d   val: %d\n", minH.top().x, minH.top().y, minH.top().val);
        return minH.top().val;
        // return 0;

    }
};








