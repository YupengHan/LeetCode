// class Solution {
// public:
    
//     /*
//         visit all child not including parent, and return the min depth of the child
//     */
//     void dfs(   int current_node,
//                 int parent_node,
//                 int depth,
//                 vector<vector<int>>& adj_list,
//                 vector<vector<int>>& bridges,
//                 vector<int>& idx_map,
//                 vector<int>& jump_map,
//                 vector<bool>& visited) {

//         visited[current_node] = true;
//         idx_map[current_node] = jump_map[current_node] = ++depth;

//         for (auto child : adj_list[current_node]) {
//             if (child == parent_node) continue;
//             else if (visited[child] == false) {
//                 dfs(child, current_node, depth, adj_list, bridges, idx_map, jump_map, visited);
//                 jump_map[current_node] = min(jump_map[current_node], jump_map[child]);
//                 if (idx_map[current_node] < jump_map[child]) {
//                     bridges.push_back({current_node, child});
//                 }
//             }
//             else { //visited[child] == true
//                 jump_map[current_node] = min(jump_map[current_node], idx_map[child]);
//             }
//         }

//     }

//     vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
//         // transform into adjacent_list
//         vector<vector<int>> adj_list(n);
//         for(auto con : connections) {
//             adj_list[con[0]].push_back(con[1]);
//             adj_list[con[1]].push_back(con[0]);
//         }

//         vector<vector<int>> bridges;
//         vector<bool> visited(n, false); //initialized 0
//         // for (int i = 0; i < n; ++i) {
//         //     cout << visited[i] << endl;
//         // }
//         vector<int> jump_map(n), idx_map(n); //initialized 0

//         dfs(0, -1, 0, adj_list, bridges,idx_map, jump_map, visited);

//         return bridges;
//     }
// };


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


/*
    第二次做这道题目
        General Idea:
        1 dfs + depth_layer(Note not time_stamp) eg:
            1 -- 2 -- 3
            |_________|
            |
            |
            4
        从node 1开始访问，
        level 0: 1
        level 1: 4 , 2 // Note that node 4 is in level 1 not in level 4, so here is depth
        level 2: 3



        2 dfs not revisiting parent!

    
    How to find circle?
        int dfs(parent, current):
            for child in current children:
                if child == parent:
                    continue;
                else if (not visited child):
                    int child_return = dfs(current, child);


    !!! Note
    vector<vector<...>> new_list(n)
                    

*/

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // convert into adj list
        vector<vector<int>> adj_list(n);
        // cout << "to here " << endl;
        for (auto con:connections) {
            adj_list[con[0]].push_back(con[1]);
            adj_list[con[1]].push_back(con[0]);
        }

        
        // int depth_map[n] = {-1};
        // cout << "to here " << endl;
        vector<int> depth_map(n, -1); //initialized 0
        // cout << "to here " << endl;

        vector<vector<int>> ret_link;

        dfs(-1, 0, 0, depth_map, adj_list, ret_link);
        return ret_link;
        
        
    }


    /*
    dfs which not going to visit the parent node and maitain a depth_map, also keep recording the return vector
    */
    int dfs(int parent, int current, int level, vector<int> &depth_map, vector<vector<int>>& adj_list, vector<vector<int>>& ret_link) {
        depth_map[current] = level;
        for (auto child:adj_list[current]) {
            if (child == parent) {
                continue;
            }
            else if (depth_map[child] == -1) {
                depth_map[child] = dfs(current, child, level+1, depth_map, adj_list, ret_link);
                depth_map[current] = min(depth_map[current], depth_map[child]);
            }
            else {
                depth_map[current] = min(depth_map[current], depth_map[child]);
            }
        }

        if (depth_map[current] == level && parent != -1) {
            cout << parent << " " << current << endl;
            ret_link.push_back({parent, current});
        }
        
        return depth_map[current];
        
    }
};