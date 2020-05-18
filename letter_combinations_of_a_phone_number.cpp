class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string dict[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        // int temp_int;
        
        vector<string> ret = {""};
        vector<string> temp;
        if (digits == "") return temp;
        for (int i = 0; i<digits.length(); i++) {
            temp.clear();
            int temp_idx = digits[i]-50;
            // cout << "temp_idx: " << temp_idx << endl;
            for (auto str:ret) {
                for (auto c:dict[temp_idx]) {
                    temp.insert(temp.end(), str+c);
                }
            }
            ret = temp;
        }

        return ret;
    }
};