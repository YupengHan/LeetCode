class Solution {
public:
    string findContestMatch(int n) {
        vector<string> myVec;
        for (int i = 0; i < n; ++i) {
            myVec.push_back(to_string(i+1));
        }
        while(n!= 1) {
            vector<string> tempVec;
            for (int i = 0; i < n/2; ++i) {
                tempVec.push_back('('+myVec[i]+','+myVec[n-1-i]+')');
            }
            myVec.clear();
            myVec.insert(myVec.end(), tempVec.begin(), tempVec.end());
            // cout << "------- n: " << n << endl;
            // for (auto x : myVec) {
            //     cout << x << " ";
            // }
            // cout << endl;
            n /= 2;
            
            
        }
        return myVec[0];
    }
};