/*
    map vector 交替使用，强行要用sort
*/
// class Solution {
// public:
//     static inline bool mycmp(pair<int, int>& a, pair<int, int>& b) {
//         return a.second > b.second;
//     }

//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> mmap;
//         for (auto n : nums) {
//             if (mmap.find(n) == mmap.end()) {
//                 mmap[n] = 1;
//             }
//             else {
//                 mmap[n] = mmap[n] + 1;
//             }
//         }

//         vector<pair<int,int>>myvec;
//         for (auto it : mmap) {
//             myvec.push_back(it);
//         }

//         sort(myvec.begin(), myvec.end(), mycmp);
//         // for (int i = 0; i < myvec.size(); ++i) {
//         //     cout << myvec[i].first << " ";
//         // }
//         vector<int> ret(k, 0);
//         for (int i = 0; i < k; ++i) {
//             ret[i] = myvec[i].first;
//         }
//         return ret;
//     }
// };

/*
    Bucket Sort
    很适合这道题这种mem换速度
*/

// PG28































