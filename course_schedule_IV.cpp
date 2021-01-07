// // TopoSort BFS
// class Solution {
// public:
//     vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
//         vector<int> in_degree(n, 0);
//         vector<int> topo_degree(n, -1);
//         vector<vector<int>> Graph(n);
//         for (auto preq : prerequisites) {
//             in_degree[preq[1]] += 1;
//             Graph[preq[0]].push_back(preq[1]);
//         }

//         queue<int> q_curr;
//         queue<int> q_next;
        

//         int degree_level = 0;
//         for (int i = 0; i < n; ++i) {

//             if (!in_degree[i]) {
//                 q_curr.push(i);
//                 cout << "i: " << i << endl;
//             }
//         }

//         while(!q_curr.empty() || !q_next.empty()) {
//             while(!q_curr.empty()) {
//                 int cur_c = q_curr.front();
//                 q_curr.pop();
//                 topo_degree[cur_c] = degree_level;
//                 for (auto to_c : Graph[cur_c]) {
//                     in_degree[to_c] -= 1;
//                     if (in_degree[to_c] == 0) {
//                         q_next.push(to_c);
//                     }
//                 }
//             }
//             degree_level++;
//             q_curr = q_next;
//             while(!q_next.empty()) {
//                 q_next.pop();
//             }

//         }

//         for (int i = 0; i < n; ++i) {
//             cout << "topo_degree[" << i << "]: " << topo_degree[i] << endl;
//         }
        
//         vector<bool> queries_ret(queries.size(), false);
//         for (int i = 0; i < queries.size(); ++i) {
//             cout << queries[i][0] << " " << queries[i][1] << endl;
//             if (topo_degree[queries[i][0]] < topo_degree[queries[i][1]]) {
//                 queries_ret[i] = true;              
//             }
//         }
//         return queries_ret;
//     }
// };

// TopoSort BFS
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> in_degree(n, 0);
        vector<int> topo_sort(n, -1);
        vector<vector<int>> Graph(n);
        for (auto preq : prerequisites) {
            in_degree[preq[1]] += 1;
            Graph[preq[0]].push_back(preq[1]);
        }

        queue<int> q;
        

        int idx = n - 1;
        for (int i = 0; i < n; ++i) {
            if (!in_degree[i]) {
                q.push(i);
                // cout << "i: " << i << endl;
            }
        }

        while(!q.empty()) {
            int cur_c = q.front();
            q.pop();
            topo_sort[idx] = cur_c;
            for (auto to_c : Graph[cur_c]) {
                in_degree[to_c] -= 1;
                if (in_degree[to_c] == 0) {
                    q.push(to_c);
                }
            }
            idx--;
        }

        vector<vector<int>> preq_list(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            preq_list[i][i] = 1;
        }
        for (int i = 0; i < n; ++i) {
            int cur_c = topo_sort[i];
            // cout << cur_c << ": ";
            for (auto to_c : Graph[cur_c]) {
                preq_list[cur_c][to_c] = 1;
                // cout << to_c << " ";
                for (int j = 0; j < n; j++) {
                    if(preq_list[to_c][j]) {
                        preq_list[cur_c][j] = 1;
                        // cout << j << " ";
                    }
                }
            }
            // cout << endl;
        }

        
        vector<bool> queries_ret(queries.size(), false);
        for (int i = 0; i < queries.size(); ++i) {
            
            if (preq_list[queries[i][0]][queries[i][1]]) {
                queries_ret[i] = true;
            }
            
        }
        return queries_ret;
    }
};