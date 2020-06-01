class Solution {
public:
    static bool comp(pair<string, int>& a, pair<string, int>& b) {
        if (a.second != b.second) {
            return (a.second > b.second);
        }
        else {
            return alpha_order(a.first, b.first)
        }
        
    }
    static bool alpha_order(string a, string b) {
        lena = a.size();
        lenb = b.size();

        bool ashort;
        int minlen;
        if (lena < lenb) {
            ashort = true;
            minlen = lena;
        }
        else {
            ashort = false;
            minlen = lenb;
        }
        bool asmall;
        for (int i = 0; i < minlen; i++) {
            if (a[i] == b[i]) {
                continue;
            }
            else if (a[i] < b[i]) {
                return true;
            }
            else {
                return false;
            }
        }
        if (ashort) {
            return true;
        }
        else {
            return false;
        }
        
        
        
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> um;
        for (int i = 0; i < words.size(); i++) {
            if (um.find(words[i]) == um.end()) {
                um[words[i]] = 1;
            }
            else {
                um[words[i]] = um[words[i]]+1;
            }
        }
        vector<pair<string, int>> eles(um.begin(), um.end());
        // cout << eles.size() << endl;
        // for (auto ele:eles) {
        //     cout << ele.first << " " << ele.second << endl;
        // }
        sort(eles.begin(), eles.end(), comp);
        vector<string> ret;
        for (int i = 0; i < k; i++) {
            ret.insert(ret.end(), eles[i].first);        
        }
        return ret;
        

        
    }
};