class Solution {
public:
    
    /*
        visit all child not including parent, and return the min depth of the child
    */
    void dfs(int current_node, int parent_node, int depth, vector<vector<int>>& adj_list, vector<vector<int>>& bridges, 
        vector<int>& idx_map,vector<int>& jump_map, vector<bool>& visited) {

        visited[current_node] = true;
        idx_map[current_node] = jump_map[current_node] = ++depth;

        for (auto child : adj_list[current_node]) {
            if (child == parent_node) continue;
            else if (visited[child] == false) {
                dfs(child, current_node, depth, adj_list, bridges, idx_map, jump_map, visited);
                jump_map[current_node] = min(jump_map[current_node], jump_map[child]);
                if (idx_map[current_node] < jump_map[child]) {
                    bridges.push_back({current_node, child});
                }
            }
            else { //visited[child] == true
                jump_map[current_node] = min(jump_map[current_node], idx_map[child]);
            }
        }

    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // transform into adjacent_list
        vector<vector<int>> adj_list(n);
        for(auto con : connections) {
            adj_list[con[0]].push_back(con[1]);
            adj_list[con[1]].push_back(con[0]);
        }

        vector<vector<int>> bridges;
        vector<bool> visited(n, false); //initialized 0
        // for (int i = 0; i < n; ++i) {
        //     cout << visited[i] << endl;
        // }
        vector<int> jump_map(n), idx_map(n); //initialized 0

        dfs(0, -1, 0, adj_list, bridges,idx_map, jump_map, visited);

        return bridges;
    }
};


/* 这道题关键点在于
    1 DFS + timestep 查询存在的环
    2   line 17 对于尚未访问的child，
                先进行dfs，(完成 jump_map[child] 的update)
                jump_map[current_node] 取 min(jump_map[current_node], jump_map[child])
        line 18 存储bridges，这时 jump_map[current_node] 尚未 update 完成，所以用idx[current_node]比较
        line 23 jump_map[current_node] = min(jump_map[current_node], idx_map[child]);
                也可以替换为：
                jump_map[current_node] = min(jump_map[current_node], jump_map[child]);
*/
