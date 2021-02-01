// 还是要考虑indgree, 只不过是逆向的，我考虑的不对！

// class Solution {
// private:
//     int mybfs(int n, vector<vector<int>>& adj_list, int s) {
//         int level = 0;
//         vector<bool> visited(n, false);
//         queue<int> q;
//         q.push(s);
//         visited[s] = true;
//         while(!q.empty()) {
//             int num = q.size();
//             while(num--) {
//                 int curnode = q.front();
//                 q.pop();
//                 for (auto tnode : adj_list[curnode]) {
//                     if (!visited[tnode]) {
//                         visited[tnode] = true;
//                         q.push(tnode);
//                     }
//                 }
//             }
//             level++;
//         }
//         return level-1;

//     }
// public:
//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//         if(edges.size() == 0) {
//             vector<int> ret;
//             for (int i = 0; i < n; ++i) {
//                 ret.push_back(i);
//             }
//             return ret;
//         }
//         vector<vector<int>> adj_list(n);
//         for (auto e : edges) {
//             adj_list[e[0]].push_back(e[1]);
//             adj_list[e[1]].push_back(e[0]);
//         }
//         vector<vector<int>> level_node(n);
//         for (int i = 0; i < n; ++i) {
//             int level = mybfs(n, adj_list, i);
//             level_node[level].push_back(i);
//         }
//         for (int i = 0; i < n; ++i) {
//             if (level_node[i].size() != 0) return level_node[i];
//         }
//         return {};
//     }
// };



class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> edge_count(n, 0);  // number of connected node
        vector<int> edge_sum(n, 0);  // sum of all connected node
        int i, n1, n2, n0 = n;
        for (vector<int> edge: edges) {
            n1 = edge[0];
            n2 = edge[1];
            edge_count[n1] ++;
            edge_count[n2] ++;
            edge_sum[n1] += n2;
            edge_sum[n2] += n1;
        }
        queue<int> q;
        for (i = 0; i < n; i ++) {
            if (edge_count[i] == 1) {
                q.push(i);
            }
        }

        int root, root1, q_size;
        while (n > 2) {
            q_size = q.size();
            for (i = 0; i < q_size; i ++) {
                root = q.front(); q.pop();
                root1 = edge_sum[root];   // leaf only connect to 1 node, sum equals to node index
                edge_sum[root1] -= root;
                edge_count[root1] --;
                if (edge_count[root1] == 1) {
                    q.push(root1);
                }
                edge_count[root] = -1;
                n --;
            }
        }
        vector<int> ans;
        for (i = 0; i < n0; i ++) {
            if (edge_count[i] > -1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};



















