class Solution {
private:
    int not_visit = 0;
    int working_on = 1;
    int visit_complete = 2;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> Graph(numCourses);
        // Build the graph
        for (auto edge : prerequisites) {
            // cout << edge[1] << " " << edge[0] << endl;
            Graph[edge[1]].push_back(edge[0]);
        }

        vector<int> Visited(numCourses, 0);
        // deque<int> ordering(numCourses, -1);
        vector<int> Ordering(numCourses, -1);
        int Cur_Idx = numCourses - 1;

        for (int i = 0; i < numCourses; ++i) {
            cout << "i:" << i << endl;
            if (Visited[i] == not_visit) {
                cout << "B: " << Cur_Idx << " " << i << " " << Ordering[0] << " " << Ordering[1]<<endl;
                Cur_Idx = dfs(i, Cur_Idx, Ordering, Visited, Graph);
                cout << "A: " << Cur_Idx << " " << i << " " << Ordering[0] << " " << Ordering[1]<<endl;
                if (Cur_Idx == -2) {
                    return {};
                }
                if (Cur_Idx == -1) {
                    return Ordering;
                }
            }
        }
        return Ordering;
    }

    int dfs(int i, int Cur_Idx, vector<int>& Ordering, vector<int>& Visited, vector<vector<int>>& Graph) {
        if (Visited[i] == working_on) {
            cout << -2 << endl;
            return -2;
        }
        // Visited[i] = working_on;
        // Not sure whether do we need this?
        // if (Visited[i] == visit_complete) {
        //     return Cur_Idx;
        // }
        
        if (Visited[i] == not_visit) {
            Visited[i] = working_on;
            for (auto edge_to : Graph[i]) {
                cout << "i" << i << "; edge_to: " << edge_to << endl;
                if (Visited[edge_to] != visit_complete) {
                    Cur_Idx = dfs(edge_to, Cur_Idx, Ordering, Visited, Graph);
                    if (Cur_Idx == -2) return -2;
                }
            }
            Ordering[Cur_Idx] = i;
            Cur_Idx = Cur_Idx - 1;
            Visited[i] = visit_complete;
            return Cur_Idx;
        }
        return Cur_Idx;
    }
};



















