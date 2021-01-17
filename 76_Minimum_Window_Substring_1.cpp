/*
    这个解答不是最短序列， 问题出在l和r的移动不是随意选择的，需要有方向指导。
    In my opinion,
    How to set the order of moving two pointers is the key


    The following answer still cannot pass the last test case, the last case is too large
        Means that build the map wasting too much time
*/ 
// class Solution {
// private:
//     bool checkt(const int l,const int r, const vector<vector<int>>& key_map,const vector<int>& t_key_cnt) {
//         for (int i = 0; i < key_map.size(); ++i) {
//             if ((key_map[i][r+1] - key_map[i][l]) < t_key_cnt[i]) {
//                 // cout << "checking " << i << " " << l << " " << r << endl;
//                 return false;
//             }
//         }
//         return true;
//     }
// public:
//     string minWindow(string s, string t) {
//         vector<int> t_key_cnt(t.size(), 1);
//         unordered_map<char, int> t_map;
//         for (auto c : t) {
//             if (!t_map.count(c)) {
//                 t_map[c] = 1;
//             }
//             else {
//                 t_map[c] = t_map[c] + 1;
//             }
//         }
//         for (int i = 0; i < t.size(); ++i) {
//             t_key_cnt[i] = t_map[t[i]];
//         }


//         vector<vector<int>> key_map(t.size(), vector<int>(s.size()+1, 0));

//         for (int j = 0; j < t.size(); ++j) {
//             key_map[j][0] = 0;
//         }
//         for (int i = 1; i <= s.size(); ++i) {
//             for (int j = 0; j < t.size(); ++j) {
//                 if (s[i-1] == t[j]) {
//                     key_map[j][i] = key_map[j][i-1] + 1;
//                 }
//                 else {
//                     key_map[j][i] = key_map[j][i-1];
//                 }
//             }   
//         }

//         int l = 0, min_l = 0;

//         int min_size = s.size()+1;


//         for (int r = 0; r < s.size(); ++r) {
//             while(checkt(l,r,key_map, t_key_cnt)) {
//                 if (!t_map.count(s[l])) {
//                     ++l;
//                     continue;
//                 }
//                 if ((r-l+1) < min_size) {
//                     min_l = l;
//                     min_size = r-l+1;
//                 }
//                 ++l;
//             }
//         }

//         return  min_size > s.size() ? "" : s.substr(min_l, min_size);


//     }
// };


class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> chars(128, 0);
        vector<bool> flag(128, false);

        for (int i = 0; i < t.size(); ++i) {
            flag[t[i]] = true;
            ++chars[t[i]];
        }

        int cnt = 0, l = 0, min_l = 0, min_size = s.size()+1;

        for (int r = 0; r < s.size(); ++r) {
            if (flag[s[r]]) {
                if(--chars[s[r]] >= 0) {
                    ++cnt;
                }
                while (cnt == t.size()) {
                    if (r-l+1 < min_size) {
                        min_l = l;
                        min_size = r-l+1;
                    }
                    if (flag[s[l]] && ++chars[s[l]] > 0) {
                        --cnt;
                    }
                    ++l;
                }
            }
        }
        return min_size > s.size() ? "" : s.substr(min_l, min_size);
    }
};































