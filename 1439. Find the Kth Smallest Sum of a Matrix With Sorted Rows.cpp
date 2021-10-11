// int global_size = 40;
// class Node {
// public:
//     int val;
//     int poses[40];
//     Node (int _val, int* _poses) {
//         this->val = _val;
//         memcpy(poses, _poses, global_size*sizeof(int));
//     }
// };
// struct cmp {
//     bool operator() (Node& a, Node& b) {
//         return a.val>b.val;
//     }
// };

// void printQ (priority_queue<Node, vector<Node>, cmp>& mQ) {
//     while (!mQ.empty()) {
//         printf("val: %d \n", mQ.top().val);
//         for (int i = 0; i < global_size; ++i) {
//             cout << *(mQ.top().poses+i) << " ";
//         }
//         cout <<endl;
//         cout << "-------------" << endl;
//         mQ.pop();
//     }
// }
// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& mat, int k) {
//         global_size = mat.size();
//         int n = mat[0].size();
//         int cur_poses[global_size];
//         int cur_val = 0;
//         for (int i = 0; i < global_size; ++i) {
//             cur_poses[i] = 0;
//             cur_val += mat[i][0];
//         }
//         set<vector<int>> visited;
//         visited.insert(cur_poses)
//         int tmp = 1;

//         priority_queue<Node, vector<Node>, cmp> mQ;
        
        
//         mQ.push(Node(cur_val, cur_poses));
//         // printQ(mQ);
//         while (tmp < k) {
//             int prev_poses[global_size];
//             memcpy(prev_poses, mQ.top().poses, global_size*sizeof(int));
//             Node prev_node = mQ.top();
//             // cout << "============" << endl;
//             cout << tmp << ": " << prev_node.val << endl;
//             mQ.pop();

//             for (int i = 0; i < global_size; ++i) {
//                 if (prev_poses[i]+1 < n) {
//                     int nval = prev_node.val + mat[i][prev_poses[i]+1] - mat[i][prev_poses[i]];
//                     prev_poses[i]++;
//                     if (!visited.count(prev_poses))
//                     mQ.push(Node(nval, prev_poses));
//                     prev_poses[i]--;
//                 }
//             }
            
//             tmp++;
//             // if (tmp == 3) {
//             //     printQ(mQ);
//             // }
//         }
//         return mQ.top().val;
//     }
// };



// // visited 的组合不要在查找啦！




class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> temp;
        set<vector<int>> vis;
        int n = mat.size(),m = mat[0].size(),sum = 0;
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>> q;
        for(int i=0;i<n;i++){
            sum+=mat[i][0];
            temp.push_back(0);
        }
        vis.insert(temp);
        q.push({sum,temp});
        while(k--){
            sum = q.top().first;
            temp = q.top().second;
            q.pop();
            if(!k)
                return sum;
            for(int i=0;i<temp.size();i++){
                if(temp[i]+1<m){
                    int curr = sum - mat[i][temp[i]] + mat[i][temp[i]+1];
                    temp[i]++;
                    if(!vis.count(temp)){
                        vis.insert(temp);
                        q.push({curr,temp});
                    }
                    temp[i]--;
                }
            }
        }
        return 0;
    }
};














