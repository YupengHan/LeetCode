#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int char_dict[strs.size()][26];
        for (int i= 0; i < strs.size(); i++) {
            for (int j = 0; j < 26; j++) {
                char_dict[i][j] = 0;
            }
        }
        
        to_dict(strs, char_dict);
        
        // for (int i= 0; i < strs.size(); i++) {
        //     for (int j = 0; j < 26; j++) {
        //         if (char_dict[i][j]) cout << '1';
        //         else cout << '0';
        //     }
        //     cout << endl;
            
        // }
        

        vector<vector<string>> ret;
        unordered_map <string, vector<string>> up;
        string temp_key;
        for (int i = 0; i < strs.size(); i++) {
            temp_key = read_dict(char_dict, i);
            up[temp_key].push_back(strs[i]);
        }
        
        // int idx = 0;
        for (auto it = up.begin(); it!= up.end(); it++) {

            ret.push_back(it->second);
        }
        return ret;

         
    }

    void to_dict(vector<string>& strs, int char_dict[][26]) {
        int str_idx = 0;
        for (auto temp_str : strs) {
            // cout << temp_str << " " << str_idx << endl;
            for (auto c : temp_str) {
                char_dict[str_idx][c-'a'] += 1;
            }
            str_idx++;
        }
    }

    string read_dict(int char_dict[][26], int idx) {
        string ret;
        for (auto b : char_dict[idx]) {
            ret += to_string(b);
        }
        return ret;
    } 
};

/* 注意　unordered_map<int, vector<string>> up
    要想导出it->second，　不需要对it->second在进行循环，直接.push_back(it->second)即可！！！！
*/