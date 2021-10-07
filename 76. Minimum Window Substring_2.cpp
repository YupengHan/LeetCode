
class Solution {
public:
    string minWindow(string s, string t) {
        // Note ASCII A-z range 102 ~ 172
        vector<int> charcnt(200, 0);
        vector<bool> flags(200, false);

        int numchar = 0;
        for (auto c:t) {
            if (!charcnt[c]) numchar++;
            charcnt[c]++;
            flags[c] = true;
            printf("c: %c; charcnt[%c]: %d \n", c, c, charcnt[c]);
        }

        string ret = s+'1';
        int cur_sat = 0;
        int l = 0; int r = 0;
        while(l < s.size() && r <= s.size()) {
            if (cur_sat == numchar) {
                // record result and update
                char cur_c = s[l];
                if ((r - l) < ret.size()) {
                    ret = s.substr(l,r-l);
                }
                
                l++;
                if (flags[cur_c]) {
                    charcnt[cur_c]++;
                    if (charcnt[cur_c] > 0) {
                        cur_sat--;
                    }
                }
            }
            else {
                while (cur_sat < numchar && r <= s.size()) {
                    char cur_c = s[r];
                    r++;
                    if (flags[cur_c]) {
                        charcnt[cur_c]--;
                        if (charcnt[cur_c] == 0) {
                            cur_sat++;
                        }
                    }
                }
            }
            
        }
        
        return ret.size() <= s.size() ? ret : "";
    }
};