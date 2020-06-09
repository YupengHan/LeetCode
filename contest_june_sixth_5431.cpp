// class Solution {
// public:
//     int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
//         int ret = minCost(houses, cost, m, n, target, -1);
//         return ret;
//     }




//     int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target, int pre_color) {
//         if (target > m) {
//             cout << "c1";
//             return -1;
//         }
//         if (n == 1 && target > 1) {
//             cout << "c2";
//             return -1;
//         }
//         int minc = INT_MAX;
//         if (target == 1) {
//             int bc = 0;
//             for (int j = 0; j < n; j++) {
//                 int cur_cnt = 0;
//                 //如果有颜色冲突
//                 for (int k = 0; k < m; k++){
//                     if (houses[k] != 0 && houses[k] != j+1) {
//                         bc = 1;
//                         break;
//                     }
//                     cur_cnt += cost[k][j];
//                 }
//                 if (bc == 1) {
//                     continue;
//                 }
//                 minc = min(cur_cnt, minc);
//             }
//             if (minc != INT_MAX) return minc;
//             return -1;
//         }
        
        
        

//         // 制造分割
        
//         for (int i = 0; i < m; i++) { //i的右侧分割
//             cout << "---------------------------" << endl;
            
//             for (int j = 0; j < n; j++) {//neighb颜色为j
                
//                 if (j == pre_color) continue; 
//                 cout << m << n << target << pre_color << j << endl;
//                 // cout << j << endl;
//                 vector<int> n_h(houses.begin()+1+i, houses.end()); // 长度小于m,return -1;
//                 vector<vector<int>> n_c(cost.begin()+1+i, cost.end());
//                 int bc = 0;
//                 int cur_cnt = 0;
//                 //如果有颜色冲突
//                 for (int k = 0; k < i+1; k++){
//                     if (houses[k] != 0 && houses[k] != j+1) {
//                         bc = 1;
//                         break;
//                     }
//                     cur_cnt += cost[k][j];
//                 }
//                 if (bc == 1) {
//                     continue;
//                 }
                
//                 int rest_cost = minCost(n_h, n_c, m-1-i, n, target-1, j);
//                 cout <<"H: ";
//                 for (auto i : n_h) {
//                     cout << i << " ";
//                 }
//                 cout <<";          rest_cost: " << rest_cost;
//                 cout << endl;
//                  // cout << i << " " << j << " " << n_h.size() << " " << n_c.size() << " " << n_c[0].size() << " " << rest_cost << endl;
//                 if (rest_cost != -1) {
//                     minc = min(cur_cnt + rest_cost, minc);
//                 }
                
//             }

//         }
//         if (minc != INT_MAX) return minc;
//         return -1;
//     }

// };