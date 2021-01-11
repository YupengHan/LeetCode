// // Toposert- BFS
// class Solution {
// public:
//     int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
//         vector<vector<pair<int,int>>> Graph(N+1);
//         vector<int> Indegree(N+1, 0);
//         vector<int> toposot(N+1, -1);
//         vector<int> ts_time(N+1, INT_MAX); //0~(N-1) order, track the minimum time

//         for (auto t:times) {
//             int from = t[0];
//             int to = t[1];
//             int ti = t[2];
//             if (to == K) {
//                 continue;
//             }
//             Graph[from].push_back(make_pair(to,ti));
//             Indegree[to]++;
//         }

//         // if (Indegree[K] != 0) return -1;
        
//         queue<int> open_box;
//         for (int i = 1; i <= N; ++i) {
//             if (Indegree[i] == 0 && i != K) {
//                 open_box.push(i);    
//             }
//         }

//         int idx = 0;
//         toposot[0] = K;
//         ts_time[K] = 0;
        
//         for (auto t_p : Graph[K]) {
//             int to_node = t_p.first;
//             int to_node_time = t_p.second;
//             Indegree[to_node]--;
//             if (Indegree[to_node] == 0 && to_node != 0) {
//                 open_box.push(to_node);
//             }
//             ts_time[to_node] = min(ts_time[to_node], to_node_time);
//         }
        

//         queue<int> print_q = open_box;
//         while(!print_q.empty()) {
//             cout << print_q.front() << " "; 
//             print_q.pop();
//         }
//         cout << endl;

//         while(!open_box.empty()) {
//             int from = open_box.front();
//             if (ts_time[from] == INT_MAX) return -1;
//             open_box.pop();

//             idx++;
//             toposot[idx] = from;

//             for (auto t_p : Graph[from]) {
//                 int to_node = t_p.first;
//                 int to_node_time = t_p.second;
//                 Indegree[to_node]--;
//                 if (Indegree[to_node] == 0) {
//                     open_box.push(to_node);
//                 }
//                 ts_time[to_node] = min(ts_time[to_node], ts_time[from]+to_node_time);
//                 // maxtime = max(ts_time[to_node], maxtime);
//             }

//         }
//         for (int i = 0; i < N; ++i) {
//             cout << toposot[i] << " ";
//         }
//         cout << endl;


//         int maxtime = 0; // track the maximum time;
//         for (int i = 1; i < N+1; ++i) {
//             cout << ts_time[i] << " ";
//             maxtime = max(ts_time[i], maxtime);
//             if (maxtime == INT_MAX) return -1;
//         }
//         cout << endl;
//         cout << "idx: " << idx << endl;
//         // if (idx != N) return -1;
//         return maxtime;

//     }
// };


// Dont think this is a toposort, Just BFS



class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        if(N<2) return 0;
        if(K>N) return -1;

        vector<vector<pair<int,int>>> Graph(N+1);
        vector<int> ts_time(N+1, INT_MAX); //0~(N-1) order, track the minimum time
        vector<bool> visit_map(N+1, false);

        for (auto t:times) {
            Graph[t[0]].push_back(make_pair(t[1],t[2]));
        }


        // int idx = -1;
        queue<int> open;
        open.push(K);
        ts_time[K] = 0;

        while(!open.empty()) {
            // idx++;
            int from = open.front();
            open.pop();

            visit_map[from] = true;
            for (auto t_p : Graph[from]) {
                int to_node = t_p.first;
                int fttt = t_p.second;

                if (ts_time[to_node] > ts_time[from] + fttt) {
                    ts_time[to_node] = ts_time[from] + fttt;
                    
                }
            }
        }

        int ret = 0;
        for (int i = 1; i <= N; ++i) {
            ret = max(ret, ts_time[i]);
        }

        return ret == INT_MAX ? -1 : ret;

    }
};