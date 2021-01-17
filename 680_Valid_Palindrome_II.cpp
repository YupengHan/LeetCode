/*
    没有想到用迭代+|| 的方式来解决树的问题！！！！
*/
// class Solution {
// public:
//     bool validPalindrome(string s) {
//         int l = 0, r = s.size()-1, del = 0;
//         while(r>=l) {
//             if (s[l] != s[r]) {
//                 del++;
//                 if (del > 1) return false;
//                 if (s[l+1] == s[r]) {
//                     l += 2;
//                     r -= 1;
//                     continue;
//                 }
//                 else if (s[l] == s[r+1]) {
//                     l += 1;
//                     r -= 2;
//                     continue;
//                 }
//                 else {
//                     return false;
//                 }


//             }
//         }
//         return true;
//     }
// };


class Solution {
public:
    boolean isPalindromeRange(string s, int i, int j) {
        for (int k = i; k <= i + (j - i) / 2; k++) {
            if (s[k] != s[j - k + i]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        for (int i = 0; i < s.length() / 2; i++) {
            if (s[i] != s.[s.size() - 1 - i]) {
                int j = s.size() - 1 - i;
                return (isPalindromeRange(s, i+1, j) ||
                        isPalindromeRange(s, i, j-1));
            }
        }
        return true;
    }
}