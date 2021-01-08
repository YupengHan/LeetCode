// class Solution {
// public:
//     vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
//         // 
//         int c_indiv = -1;

//         for (int i = 0; i < group.size(); i++) {
//             if (group[i] == -1) {
//                 group[i] = c_indiv;
//                 c_indiv--;
//             }
//         }
//         // for (auto g : group) {
//         //     cout << g << endl;
//         // }
//         // cout << -1 - c_indiv << endl;
//         int i_cnt = (-1 - c_indiv);
//         int g_cnt = i_cnt + m; // total group num
//         cout << g_cnt << endl;

//         // Sort Group, Get a vector<int> sorted_group;
//         vector<vector<int>> group_relations(g_cnt);
//         vector<int> sorted_group (g_cnt,c_indiv+1);
//         vector<int> group_indegree(g_cnt,0);
        
//         for (int i = 0; i < beforeItems.size(); ++i) {
//             for (auto bi : beforeItems[i]) {
//                 // cout << group[bi]+i_cnt << endl;
//                 // cout << group[i]+i_cnt << endl;
//                 int g_f = group[bi]+i_cnt;
//                 int g_b = group[i]+i_cnt;
//                 if (g_f != g_b) {
//                     group_relations[g_f].push_back[g_b];
//                     group_indegree[g_b]++;    
//                 }
                
//             }
//         }
//         queue<int> gq;
//         for (int i = 0; i < g_cnt; ++i) {
//             if (group_indegree[i] == 0) {
//                 gq.push(i-i_cnt); //Here is idx+i_cnt
//             }
//         }

//         int c_group_idx = 0;
//         while(!gq.empty()){
//             int c_g = gq.front();
//             gq.pop();
//             sorted_group[c_group_idx] = c_g;
//             c_group_idx++;
//             for (auto to_g : group_relations[c_g+i_cnt]) {
//                 group_indegree[to_g]--;
//                 if (group_indegree[to_g] == 0) {
//                     gq.push(to_g-i_cnt);
//                 }
//             }
//         }
//         for (int i = 0; i < g_cnt; ++i) {
//             cout << sorted_group[i];
//         }



//         return {};
//     }
// };
class Solution {
private:
    // topological sorting using Kahn's algorithm
    void topologicalSort(int start, vector<int> adj[], vector<int> &indegrees, vector<int> &result) {
        queue<int> sortedItems;
        sortedItems.push(start);
        while(!sortedItems.empty()) {
            int elem = sortedItems.front();
            sortedItems.pop();
            result.push_back(elem);
            for(int i = 0; i < adj[elem].size(); i++) {
                int child = adj[elem][i];
                indegrees[child]--;
                if(indegrees[child] == 0) {
                    sortedItems.push(child);
                }
            }
        }
    }
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        //We create dummy nodes(one node for ending group and another for starting group element) for each group and attach each group element for that group to that.
        //if dependencies are intergroup, create an edge from ending nodes for group and
        //and starting nodes for group
        //numbering of group starting and ending is done like this: n, n+1, n+2 etc
        //for eg: n = 7 that means vertex will be from 0-6, so we create dummy nodes for group 0 as n + 2* groupNumber i.e. 7 and ending nodes for same group as n + 2*groupNumber + 1 = 8
        //this way instead of doing 2 level topologicalsort, we will do single level topologicalsort
        //dummy nodes
        int sizeOfGroupsArray = group.size();
        //+1 factor for all nodes that belong to -1 group, no group
        int totalNumberOfNodes = n + (m + 1) * 2;
        vector<int> indegrees(totalNumberOfNodes, 0);
        vector<int> result;
        vector<int> adj[totalNumberOfNodes];
        int beforeItem;
        for(int i = 0; i < sizeOfGroupsArray; i++) {
            if(group[i] == -1) {
                group[i] = m;
            }
            int groupStartingNode = 2 * group[i] + n;
            int groupEndingNode = 2 * group[i] + n + 1;
            adj[groupStartingNode].push_back(i);
            adj[i].push_back(groupEndingNode);
            indegrees[i]++;
            indegrees[groupEndingNode]++;
        } 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < beforeItems[i].size(); j++) {
                beforeItem = beforeItems[i][j];
                if(group[i] != group[beforeItem]) {                                         
                    adj[2 * group[beforeItem] + n + 1].push_back(2* group[i] + n);
                    indegrees[2* group[i] + n]++;
                } else {
                    adj[beforeItem].push_back(i);
                    indegrees[i]++;
                }
            }
        }
     
        vector<int> startingNodes;
        vector<int> resultWithExtraNodes;
        for(int i = 0; i < totalNumberOfNodes; i++) {
            if(indegrees[i] == 0) {
                startingNodes.push_back(i);
            }
        }
        for(int i = 0; i < startingNodes.size(); i++) {
            topologicalSort(startingNodes[i], adj, indegrees, resultWithExtraNodes);
        }
        //remove extra dummy nodes
        for(int i = 0; i < resultWithExtraNodes.size(); i++) {
            if(resultWithExtraNodes[i] >= n)
                continue;
            result.push_back(resultWithExtraNodes[i]);
        }
        if(result.size() == n) {
            return result;
        } else {
            return vector<int>();
        }
    }
};