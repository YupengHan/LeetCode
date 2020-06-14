// 超时算法
// class Solution {
// public:
//     static bool sortbysec(pair<int, int>&a, pair<int, int>&b){
//         return (a.second < b.second);
//     }
//     int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
//         if (k == arr.size()) {
//             return 0;
//         }
        
//         vector<pair<int, int>> mykp;
//         unordered_map<int, int> mmp;
//         for (int i = 0; i < arr.size(); i++) {
//             if (mmp.count(arr[i])) {
//                 mmp[arr[i]]++;
//             }
//             else {
//                 mmp[arr[i]] = 1;
//             }
//         }

//         for (auto it = mmp.begin(); it != mmp.end(); it++) {
//             // cout << it->first << it->second << endl;
//             mykp.insert(mykp.begin(), make_pair(it->first, it->second));
//         }
//         sort(mykp.begin(), mykp.end(), sortbysec);
//         // for (auto it = mmp.begin(); it != mmp.end(); it++) {
//         //     cout << it->first << it->second << endl;
//         //     // mykp.push_back(make_pair(it->first, it->second));
//         // }
//         int ret = mykp.size();
//         // cout << ret << endl;
//         while(k > 0) {
//             ret--;
//             k = k - mykp.begin()->second;
//             mykp.erase(mykp.begin());
//         }
//         if (k == 0) return ret;
        
//         return ret+1;
        
        
//     }
// };