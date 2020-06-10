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
            buildRelation(words[i-1], words[i]);
        }
        
        // for (auto x:a_r) {
        //     cout << x.first << " > " << x.second << endl;
        // }
        
        
        
        
        string ret = "";
        while (!a_d.empty()) {
            for (auto cur_c:a_d) {
                cout << cur_c << endl;
                int find_sig = 0;
                for (auto rel:a_r) {
                    if (rel.second == cur_c) {
                        find_sig = 1;
                        break;
                    } 
                }
                if (find_sig == 0) { // 头部字母
                    cout << cur_c << endl;
                    ret += cur_c;
                    a_d.erase(cur_c);
                    for (int i = 0; i < a_r.size(); i++) {
                        cout << i << endl;
                        pair<char, char> cur_rel = a_r[i];
                        if (cur_rel.first == cur_c) {
                            cout << cur_rel.first << " > " << cur_rel.second << " " << i << endl;
                            a_r.erase(a_r.begin()+i);
                            cout << "-----" << a_r.size() << "-----" << endl;
                            for (auto x:a_r) {
                                cout << x.first << " > " << x.second << endl;
                            }
                            cout << "---51----" << endl;
                        }
                        
                    }
                    continue;
                }

            }
            
            
        }
        return ret;
        
    }
    void buildRelation (string a, string b) {
        int min_size = min(a.size(), b.size());
        for (int i = 1; i <= min_size; i++) {
            if (a.substr(0,i) != b.substr(0,i)) {
                a_r.insert(a_r.begin(),make_pair(a[i-1], b[i-1]));
                return;
            }
        }
    }
};