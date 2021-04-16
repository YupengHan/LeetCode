class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, int> mSMap;
        for (int i = 0; i < S.size(); ++i) {
            
            // mSMap[S[i]] = i;
            mSMap.emplace(S[i], i);
            // mSMap.insert({S[i], i});
        }

        // for (auto iter = mSMap.begin(); iter != mSMap.end(); ++iter) {
        //     cout << iter->first << " " << iter->second << endl;
        // }



        vector<vector<int>> sList(S.size());
        vector<int> restIdxs;
        for (int i = 0; i < T.size(); ++i) {
            if (mSMap.count(T[i])) {
                
                sList[mSMap[T[i]]].push_back(i);
            }
            else {
                restIdxs.push_back(i);
            }
        }
        // cout << 28 << endl;
        string s = "";
        for (auto l : sList) {
            for (auto i:l) {
                s += T[i];
                // cout << s << endl;
            }
        }
        for (auto i : restIdxs) {
            s += T[i];
        }
        return s;


    }
};