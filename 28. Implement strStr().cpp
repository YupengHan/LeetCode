class Solution {
public:
    int BASE = 1000000;
    int strStr(string haystack, string needle) {
        // if (haystack.empty() || needle.empty()) {
        //     return -1;
        // }

        int nlen = needle.size();
        if (nlen == 0) {
            return 0;
        }



        int maxPower = 1;
        for (int i = 0; i < nlen; ++i) {
            maxPower = (maxPower*31) % BASE;
        }
        // cout << maxPower << endl;

        int targetHashNum = 0;
        for (int i = 0; i < nlen; ++i) {
            targetHashNum = (targetHashNum * 31 + needle[i]) % BASE;
        }
        // cout << targetHashNum << endl;

        int curHashNum = 0;
        for (int i = 0; i < haystack.size(); ++i) {
            curHashNum = (curHashNum * 31 + haystack[i]) % BASE;

            if (i < nlen -1) {
                continue;
            }

            if (i >= nlen) {
                curHashNum = curHashNum - (haystack[i-nlen]* maxPower) % BASE;
                if (curHashNum < 0) {
                    curHashNum += BASE;
                }
                // cout << i << " " << curHashNum << endl;
            }

            if (curHashNum == targetHashNum) {
                if (haystack.substr(i-nlen+1, nlen) == needle) {
                    return i-nlen+1;
                }
            }
        }
        return -1;
    }
};
