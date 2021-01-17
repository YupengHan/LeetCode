/*
    这个解答不是最短序列， 问题出在l和r的移动不是随意选择的，需要有方向指导。
    In my opinion,
    How to set the order of moving two pointers is the key
*/ 




class Solution {
private:
    bool checkt(int l, int r, const vector<vector<int>>& key_map, vector<int>& t_key_cnt) {
        for (int i = 0; i < key_map.size(); ++i) {
            if ((key_map[i][r+1] - key_map[i][l]) < t_key_cnt[i]) {
                // cout << "checking " << i << " " << l << " " << r << endl;
                return false;
            }
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        
        vector<int> t_key_cnt(t.size(), 1);
        unordered_map<char, vector<int>> s_map;
        unordered_map<char, int> t_map;
        for (auto c : t) {
            if (!t_map.count(c)) {
                t_map[c] = 1;
            }
            else {
                t_map[c] = t_map[c] + 1;
            }
        }
        for (int i = 0; i < t.size(); ++i) {
            t_key_cnt[i] = t_map[t[i]];
        }


        vector<vector<int>> key_map(t.size(), vector<int>(s.size()+1, 0));

        for (int j = 0; j < t.size(); ++j) {
            key_map[j][0] = 0;
        }
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < t.size(); ++j) {
                if (s[i-1] == t[j]) {
                    key_map[j][i] = key_map[j][i-1] + 1;
                    s_map[t[j]].push_back(i-1);
                    cout << "can do new push" << endl;
                }
                else {
                    key_map[j][i] = key_map[j][i-1];
                }
            }   
        }

            ABBBCDDCCEFA
            A0111111111112
            B0012333333333
            C0000011123333

              ABBBCDDCCEFA
            A{0,A}
            B{1,2,3}
            C{4,7,8}

              ABBBCDDCCEFA
            A-00000000000A
            B---1222222222
            C--------47777
        
        // for(int i = 0; i < t.size(); i++) {
        //     cout << t[i] << ": ";
        //     for (int j = 0; j < s.size()+1; j++) {
        //         cout << key_map[i][j];
        //     }
        //     cout << endl;
        // }

        
        
        return {};

    }

// };




// //   ABBBCDDC
// // A011111111
// // B001233333
// // C000001112
/*
  ABBBCDDCCEFA
A0111111111112
B0012333333333
C0000011123333

  ABBBCDDCCEFA
A{0,A}
B{1,2,3}
C{4,7,8}

  ABBBCDDCCEFA
A-00000000000A
B---1222222222
C--------47777

A1B2C2



  ABBBCDDCCEFA A1B2C2
A-00000000000A
B---1222222222
C--------47777
*/









