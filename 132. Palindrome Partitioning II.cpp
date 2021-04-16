// Prep DP Time Limit Exceed
// class Solution {

// public:
//     int minCut(string s) {
//         int n = s.size();
//         vector<vector<bool>> isPalMap(n, vector<bool>(n+1, false));
//         for (int i = 0; i < n; ++i) {
//             for (int j = i+1; j <= n; ++j) {
//                 isPalMap[i][j] = isPar(s.substr(i, j-i));
//             }
//         }

//         // return 0;
//         queue<int> myQueue;
//         myQueue.push(0);
//         int retlevel = -1;
//         while(!myQueue.empty()) {
//             retlevel++;
//             int size = myQueue.size();
//             for (int i = 0; i < size; ++i) {
//                 int st = myQueue.front();
//                 myQueue.pop();

//                 for (int curEnd = st+1; curEnd <= s.size(); ++curEnd) {
//                     if (isPalMap[st][curEnd]) {
//                         if (curEnd == s.size()) return retlevel;
//                         myQueue.push(curEnd);
//                     }
//                 }
//             }
//         }
//         return -1;


//     }

// private:

//     bool isPar(string s) {
//         int l = 0, r = s.size()-1;
//         while(l<r) {
//             if (s[l] != s[r]) return false;
//             l++;
//             r--;
//         }
//         return true;
//     }

// };




// BFS
// class Solution {
// public:
//     int minCut(string s) {
//         vector<bool> visited(s.size()+1, false);
//         queue<int> myQueue;
//         myQueue.push(0);
//         visited[0] = true;

//         int retLevel = 0;
//         while(!myQueue.empty()) {
//             int size = myQueue.size();
//             for (int i = 0; i < size; ++i) {
//                 int st = myQueue.front();
//                 // cout << st << endl;
//                 myQueue.pop();
//                 for (int j = st+1; j <= s.size(); ++j) {
//                     if (isPar(s.substr(st, j-st))) {
//                         // cout << i << " " << s.substr(st, j-st) << endl;
//                         if (j == s.size()) return retLevel;
                        
//                         if (visited[j]) continue;
//                         myQueue.push(j);
//                         visited[j] = true;


//                     }
//                 }

//             }


//             retLevel++;
//         }
//         return -1;
//     }


// private:

//     bool isPar(string s) {
//         int l = 0, r = s.size()-1;
//         while(l<r) {
//             if (s[l] != s[r]) return false;
//             l++;
//             r--;
//         }
//         return true;
//     }
// };




// DP with isPar func
// Exceed Time Limit
// class Solution {
// public:
//     int minCut(string s) {
//         vector<int> dp(s.size()+1, 0);
//         for (int i = 1; i <= s.size(); ++i) {
//             dp[i] = dp[i-1] + 1;
//             for (int j = 0; j < i; ++j) {
//                 if (isPar(s.substr(j,i-j))) {
//                     dp[i] = (1+dp[j] < dp[i]) ? 1+dp[j] : dp[i];
//                 }
//             }
//         }
//         return dp[s.size()];
//     }
// private:

//     bool isPar(string s) {
//         int l = 0, r = s.size()-1;
//         while(l<r) {
//             if (s[l] != s[r]) return false;
//             l++;
//             r--;
//         }
//         return true;
//     }
// };


class Solution {
public:
    int minCut(string s) {
        vector<int> dp(s.size()+1, 0);
        for (int i = 1; i <= s.size(); ++i) {
            dp[i] = dp[i-1] + 1;
            for (int j = 1; j < i; ++j) {
                if (s[j-1] == s[i-1] && dp[j+1] == dp[i-1]) {
                    dp[i] = (dp[j+1] < dp[i]) ? dp[j+1] : dp[i];
                    cout << "           " << j <<" " <<i << endl;
                }
                if (s[j-1] == s[i-1]) {
                    cout << "           " << j << " " <<i << endl;
                }
            }
            cout << "dp[" << i << "]: " << dp[i] << endl;
        }
        return dp[s.size()]-1;
    }
};


























