class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        aa("", n, 0, ret);
        return ret;
    }
    void aa(string str, int l, int r, vector<string>& ret) {
        if (l < 0 || r < 0) {
            return;
        }
        if (l == 0 && r == 0) {
            ret.insert(ret.end(), str);
        }
        aa(str+"(", l-1, r+1, ret);
        aa(str+")", l , r-1, ret);

    }
};


// class Solution {
// public:
//     vector<string> generateParenthesis(int n) {
//         std::vector<string> v;
//         backtrack(v, "", 0, 0, n);
//         return v;
//     }
    
// private:
//     void backtrack(std::vector<string>& v, string cur, int open, int close, int npairs) {
//         if (cur.length() == 2 * npairs) {
//             v.push_back(cur);
//             return;
//         }
//         if (open < npairs) {
//             backtrack(v, cur + "(", open + 1, close, npairs);
//         }
//         if (close < open) {
//             backtrack(v, cur + ")", open, close + 1, npairs);
//         }
//     }
// };