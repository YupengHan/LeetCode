class Solution {
private:
    bool deleteS(string s, string b) {
        int i = 0;
        int j = 0;
        while(j < b.size() && i < s.size()) {
            if (s[i]==b[j]) {
                i++;
                j++;   
            }
            else {
                i++;
            }
        }
        if (j == b.size()) return true;
        return false;
    }
    // bool lexicographical(string a, string b) {
    //     for (int i = 0; i < a.size(); ++i) {
    //         if ((a[i]-'a') < (b[i]-'a')) {
    //             return true;
    //         }
    //         else if ((b[i]-'a') < (a[i]-'a')){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](string a, string b) {
            if (a.size() == b.size()) {
                for (int i = 0; i < a.size(); ++i) {
                    if ((a[i]-'a') < (b[i]-'a')) {
                        return true;
                    }
                    else if ((b[i]-'a') < (a[i]-'a')){
                        return false;
                    }
                }
                return true;
            }
            return  a.size() > b.size();
        });
        for (auto w : d) {
            // cout << w << " ";
            if (deleteS(s,w)) return w;
        }

        return "";
    }
};