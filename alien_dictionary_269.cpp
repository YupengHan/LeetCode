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