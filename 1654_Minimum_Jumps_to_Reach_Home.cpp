// class Solution {
// public:
//     int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
//         vector<int> st_map(4000, 4000);
//         vector<bool> jump_back(4000, true);
//         for (auto f : forbidden) {
//             st_map[f] = -2;
//         }
//         queue<int> open;
//         open.push(0);
//         st_map[0] = 0;
//         jump_back[0] = true;

//         while(!open.empty()){
//             int cur_pose = open.front();
//             open.pop();
//             if ((cur_pose+a) < 4000) {
//                 if (st_map[cur_pose+a] > st_map[cur_pose]+1) {
//                     st_map[cur_pose+a] = st_map[cur_pose] + 1;
//                     jump_back[cur_pose+a] = true;
//                     open.push(cur_pose+a);
//                 }
//             }
//             if ((cur_pose-b) > -1  && jump_back[cur_pose]) {
//                 if (st_map[cur_pose-b] > st_map[cur_pose]+1) {
//                     st_map[cur_pose-b] = st_map[cur_pose] + 1;
//                     jump_back[cur_pose+a] = false;
//                     open.push(cur_pose-b);
//                 }
//             }
//         }
//         return st_map[x] == 4000 ? -1 : st_map[x];
//     }
// };

using tup = tuple<int, int, bool>; // location, count, previous_jump(forward or backward)
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        queue<tup> que; // forward true
        set<pair<int, bool>> seen; //previous jump direction with its location
        que.push({0, 0, true});
        for (int i : forbidden) 
            seen.insert({i, true}), seen.insert({i, false});
        while (!que.empty()) {
            auto [loc, count, forward] = que.front();
            que.pop();
            if (loc == x) 
                return count;
            else if (seen.count({loc, forward}) || loc > 6000)
                continue;
            seen.insert({loc, forward});
            que.push({loc + a, count + 1, true});
            if (forward && loc >= b)
                que.push({loc - b, count + 1, false});
        }
        return -1;
    }
};