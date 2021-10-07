// 10007
class Solution {
public:

    int strStr(string haystack, string needle) {
        int base = 10007;
        if (needle.size() > haystack.size()) return -1;
        int nlen = needle.size();
        int nRem = 1;
        for (int i = 0; i < nlen; ++i) {
            nRem = (nRem*31) % base;
        }

        for (int i = 0; i < haystack.size() - nlen + 1; ++i) {
            printf("haystack[%d]: %c\n", i, haystack[i]);

            // if (haystack.substr(i, nlen) == needle) {
            //     return i;
            // }
            int hRem = 1;
            for (int j = 0; j < nlen; ++j) {
                hRem = (hRem*31) % base;
            }
            if (nRem == hRem) {
                if (haystack.substr(i, nlen) == needle) {
                    return i;
                }
            }
        }
        return -1;
    }
};