/*
BFS with map
*/
// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set <string> dict(wordDict.begin(), wordDict.end());
//         vector <bool> visited(s.size());
//         queue <int> q;
//         q.push(0);

//         while (!q.empty()) {
//             int k = q.size();
//             // cout << "-----------------" << endl;
//             for (int i = 0; i < k; i++) {
//                 int start = q.front();
//                 // cout << s[start] << " " << start << endl;
//                 q.pop();
//                 if (!visited[start]) {
//                     for (int end = start+1; end <= s.size(); end++) {
//                         // cout << end << " start: " << start << endl;
//                         if (dict.find(s.substr(start, end-start)) != dict.end()) {
//                             // cout << s.substr(start, end-start) << endl;
//                             if (end == s.size()) return true;
//                             q.push(end);
//                         }
//                     }
//                     visited[start] = true;
//                 }
//             }
//             // cout << "++++++++++++++++++" << endl;
            
//         }
//         return false;
        
        
//     }
// };


/*
极快!!!
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        queue <string> q;
        q.push(s);
        vector<bool> visited(s.size()) = {flase};
        while (!q.empty()) {
            int k = q.size();
            // cout << "---------------------" << endl;
            for (int i = 0; i < k; i++) {
                string cur_s = q.front();
                // cout << cur_s << endl;
                q.pop();
                if (!visited[s.zie()-cur_s.size()]) {
                    visited[s.zie()-cur_s.size()] = true;
                    for (int j = 0; j < wordDict.size(); j++) {
                        string cur_w = wordDict[j];
                        
                        if (component(cur_s, cur_w)) {
                            // cout << cur_w << endl;
                            if (cur_s.size() == cur_w.size()) {
                                return true;
                            }
                            else {
                                q.push(cur_s.substr(cur_w.size(), s.size()-1));
                            }
                        }   
                    }
                }
                

                
            }

            
        }
        return false;
        
        
    }
    bool component(string s, string a) {
        if (a.size() > s.size()) return false;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != s[i]) {
                return false;
            }
        }
        return true;
    }
};