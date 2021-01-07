class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> in_degree(n, 0);
        // vector<int> topo_sort(n, -1);
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
            int cur_c = q_curr.front();
            q_curr.pop();
            // topo_sort[idx] = cur_c
            for (auto to_c : Graph[cur_c]) {
                in_degree[to_c] -= 1;
                if (in_degree[to_c] == 0) {
                    q.push(to_c);
                }
            }
            idx--;
        }

        vector<vector<int>> preq_list(n);
        for (int i = 0; i < n; ++i) {
            preq_list[i].push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            // int cur_c = topo_sort[i];
            for (auto to_c : Graph[cur_c]) {
                in_degree[to_c] -= 1;
                if (in_degree[to_c] == 0) {
                    q.push(to_c);
                }
            }
        }

        
        vector<bool> queries_ret(queries.size(), false);
        for (int i = 0; i < queries.size(); ++i) {
            cout << queries[i][0] << " " << queries[i][1] << endl;
        }
        return queries_ret;
    }
};