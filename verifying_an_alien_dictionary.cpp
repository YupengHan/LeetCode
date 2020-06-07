class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < order.size(); i++) {
            dict[order[i]] = i;
        }
        for (int i = 0; i < words.size()-1; i++) {
            if (!com(words[i], words[i+1])) {
                return false;
            }
            
        }
        return true;
        
    }
private:
    unordered_map<string, int> dict;
    bool com (string a, string b) {
        int len = min(a.length(), b.length());
        // int eql = 1;
        for (int i = 0; i < len; i++) {
            if (dict[a[i]] > dict[b[i]] {
                return false;
            }
        }

        if (a.substr(0,len) == b.substr(0,len)) {
            if (a.size() > b.size()) {
                return false;
            }
            
        }
        
        return true;
    }
};