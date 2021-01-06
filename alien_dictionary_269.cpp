class Solution {
private:
    unordered_set<char>  a_d; // dict
    vector<pair<char, char>> a_r; // relations
public:
    string alienOrder(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            string tmp_w = words[i];
            for (auto c:tmp_w) {
                if (!a_d.count(c)) {
                    a_d.insert(c);
                }
            }
        }

        for (int i = 1; i < words.size(); i++) {
            int t = buildRelation(words[i-1], words[i]);
            if (t == -1) {
                return "";
            }
            
        }
        
        // for (auto x:a_r) {
        //     cout << x.first << " > " << x.second << endl;
        // }
        
        
        
        
        string ret = "";
        // checking possible solution
        

        while (!a_d.empty()) {
            queue <char> delete_char;
            for (auto cur_c:a_d) {
                // cout << cur_c << endl;
                int find_sig = 0;
                for (auto rel:a_r) {
                    if (rel.second == cur_c) {
                        find_sig = 1;
                        break;
                    } 
                }
                if (find_sig == 0) { // 头部字母
                    delete_char.push(cur_c);
                }
            }

            if (delete_char.empty() && !a_d.empty()) {
                return "";
            }
            

            while(!delete_char.empty()) {
                char cur_c = delete_char.front();
                delete_char.pop();
                ret += cur_c;
                a_d.erase(cur_c);
                for (int i = 0; i < a_r.size(); i++) {
                    if (a_r[i].first == cur_c) {
                        a_r.erase(a_r.begin()+i);
                        i--;
                    }
                }
            }
            
            
        }
        return ret;
        
    }
    int buildRelation (string a, string b) {
        int min_size = min(a.size(), b.size());
        for (int i = 1; i <= min_size; i++) {
            if (a.substr(0,i) != b.substr(0,i)) {
                a_r.insert(a_r.begin(),make_pair(a[i-1], b[i-1]));
                return 0;
            }
        }
        if (a.size() > b.size()) {
            return -1;
        }
        return 0;
        
    }
};














// Topological Sort + DFS

class Solution {
private: 
    int not_visit = 0;
    int working_on = 1;
    int visit_compelte = 2;
    int cycle_detect = -2;
public:
    string alienOrder(vector<string>& words) {
        if (words.size() == 1) return words[0];
        int char_num = 0;
        unordered_map<char, int> visit_map;
        unordered_map<char, vector<char>> Graph;
        // Build Graph
        for (auto word : words) {
            for (auto c : word) {
                if (!visit_map.count(c)) {
                    visit_map[c] = 0;
                    char_num++;
                }
            }
        }
        for (int i = 1; i < words.size(); ++i) {
            build_graph(words[i-1], words[i], Graph);
        }

        string alien_dict(char_num, '0');
        int idx = char_num - 1;

        unordered_map<char, int>::iterator iter;
        for (iter = visit_map.begin(); iter != visit_map.end(); ++iter) {
            char c_char = iter->first;
            // cout << c_char << endl;
            if (iter->second == 0) {
                // cout << c_char << " " << iter->second << endl;
                idx = dfs(c_char, idx, alien_dict, visit_map, Graph);
                if (idx == cycle_detect) return "";
            }
        }
        // cout << "idx " << idx << endl;
        if (idx != -1) return "";
        return alien_dict;
    }

    void build_graph(string w1, string w2, unordered_map<char, vector<char>>& Graph) {
        for (int i = 0; i < w1.size(); ++i) {
            if (w1[i] != w2[i]) {
                Graph[w1[i]].push_back(w2[i]);
                return;
            }
        }
    }

    int dfs(char c_char, int idx, string& alien_dict, unordered_map<char, int>& visit_map, unordered_map<char, vector<char>>& Graph) {
        if (visit_map[c_char] == working_on) {
            return cycle_detect;
        }

        if (visit_map[c_char] == not_visit) {
            visit_map[c_char] = working_on;
            for (char to_char : Graph[c_char]) {
                // cout << c_char << " to: " << to_char << endl;
                if (visit_map[to_char] == not_visit) {
                    idx = dfs(to_char, idx, alien_dict, visit_map, Graph);
                    if (idx == cycle_detect) return cycle_detect;
                }
            }
            alien_dict[idx] = c_char;
            cout << "alien_dict[" << idx << "]: " << alien_dict[idx] << endl;
            idx--;

        }
        return idx;
    }

};


































