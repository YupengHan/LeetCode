class Solution {
public:
    bool rotateString(string A, string B) {
        if (A == "" && B == "") return true;
        if (A.size() != B.size()) return false;
        for (int i = 0; i < B.size(); ++i) {
            if (A[0] == B[i]) {
                bool sig = true;
                for (int j = 1; j < A.size(); ++j) {
                    if (A[j] != B[(j+i)%B.size()]) {
                        sig = false;
                        break;
                    }
                }
                if (sig) return true;
            }
        }
        return false;
    }
};