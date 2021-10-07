class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int i, j = 0, count = s.size();

        unordered_set <char> mSet;
        mSet.insert(s[j]);
        j++;
        int ret = 1;
        int c_len = 1;
        for (int i = 0; i < count; i++) {
            while (j < count && mSet.find(s[j]) == mSet.end() ) {
                // c_len = j - i + 1;
                mSet.insert(s[j]);
                c_len = mSet.size();
                // cout << i << " " << j << " " << c_len << endl;
                ret = max(ret, c_len);
                j++;
            }
            
            // if (mSet.find(s[j]) != mSet.end()) {
            //     ret = max(ret, c_len);
            // }
            // else if (j == count - 1){
            //     return ret;
            // }
            mSet.erase(s[i]);
        }
        return ret;
        
    }
};