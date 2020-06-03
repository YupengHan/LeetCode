/*
    超时答案
*/
// class Solution {
// public:
//     vector<string> wordBreak(string s, vector<string>& wordDict) {
//         unordered_set wd(wordDict.begin(), wordDict.end());
//         queue<vector<string>> q;
//         vector<string> ret;
//         q.push({});
//         while (!q.empty()) {
//             int k = q.size();
//             // cout << "-----------------" << endl;
//             for (int i = 0; i < k; i++) {
//                 // cout << "           " << endl;
//                 vector<string> cur_v = q.front();
//                 q.pop();
//                 int start=0;
//                 if (!cur_v.empty()) {
//                     for (auto ele:cur_v) {
//                         start += ele.size();
//                         cout << ele << endl;
//                     }
//                 }
//                 // cout << "out prev" << endl;

//                 for (int end = start+1; end <= s.size(); end++) {
//                     if (wd.find(s.substr(start, end-start)) != wd.end()) {
//                         // cout << s.substr(start, end-start) << endl;
//                         vector <string> tmp_v = cur_v;
//                         tmp_v.insert(tmp_v.end(), s.substr(start, end-start));
//                         if (end == s.size()) {
//                             // ret.insert(ret.end(), cur_v);
//                             ret = convert2ret(ret, tmp_v);
//                         }
//                         else {
//                             q.push(tmp_v);
//                         }
                        
//                     }
                    
//                 }
                
                
//             }
            
//         }
//     return ret;
        
//     }

//     vector<string> convert2ret(vector<string> ret, vector<string>v) {
//         string s = "";
//         for (auto ele:v) {
//             s += ele;
//             s += " ";
//         }
//         s = s.substr(0, s.size()-1);
//         ret.insert(ret.end(), s);
//         return ret;
//     }
// };



// 这个算法的空格处理有点儿问题

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wd(wordDict.begin(), wordDict.end());
        
        mem_[""] = {""};
        
        // 这个必须用一个类似的recursive的方式写
        // for (int i = 0; i < wd.size(); i++) {
        //     vector<string> cur_w;
        //     cur_w.insert(cur_w.end(),wd[i]);
        //     for (int j = 1; j < wd[i].size(); j++) {
        //         string left = 
        //     }
        // }
        
        // 这个是有问题的
        // for (auto w:wd) {
        //     mem_[w]={w};
        // }
        
        if (wb(s, wd)) {
            // vector<string> ret = mem_[s];
            // sort(ret.begin(), ret.end());
            // ret.erase(unique(ret.begin(), ret.end()), ret.end());
            // return ret;
            
            return mem_[s];
        }
        else {
            return {};
        }
        
        
    }
    

private:
    unordered_map<string, vector<string>> mem_;

    bool wb(string s, unordered_set<string> wd) {
        // cout << "----" + s + "----" << endl;
        if (mem_.count(s)) {
            return true;
        }
        
        vector<string> mem_s;
        if (wd.count(s)) {
            // cout << "Indict :" << s << endl;
            mem_s.insert(mem_s.end(), s);
        }
        
        for (int i = 1; i < s.size(); i++) {
            string right = s.substr(i);
            string left = s.substr(0,i);
            if (!mem_.count(right) && !wd.count(right)) {
            // -----------------------------------------------------------------------
            // Notice Need to do by word not checking for the mem_
            // 问题是这样的,在append的过程中,我们没有区分mem_和wd,wd可以直接按照目前的append进行,但是mem_需要多家一个" "!!!!!!!
            // 这个改进太繁杂了,我直接去该app
            // -----------------------------------------------------------------------
            // if (!wd.count(right)) {
                continue;
            }
            if (wb(left,wd)) {
                // cout << "left: " << left << "; right: " << right << endl;
                if (!wd.count(right) && mem_.count(right)) {
                    right = " " + right;
                }
                
                vector<string> tmp = app(right, mem_[left]);
                mem_s.insert(mem_s.end(), tmp.begin(), tmp.end());
            }

        }

        if (!mem_s.empty()) {
            mem_[s] = mem_s;
            return true;
        }
        else {
            return false;
        }
        
        
    }

    vector<string> app(string s, vector<string> v_s) {
        vector<string> ret;
        for (auto cs:v_s) {
            if (cs[cs.size()-1] == " ") {
                ret.insert(ret.end(), cs+s);
            }
            else {
                ret.insert(ret.end(), cs+" "+s);
            }
            
        }
        return ret;
    }

};



/*
Notice only this working, my not working!!!!
*/
// class Solution {
// public:
//     vector<string> wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
//         return wordBreak(s, dict);
//     }
// private:
//     // >> append({"cats and", "cat sand"}, "dog");
//     // {"cats and dog", "cat sand dog"}
//     vector<string> append(const vector<string>& prefixes, const string& word) {
//         vector<string> results;
//         for(const auto& prefix : prefixes)
//             results.push_back(prefix + " " + word);
//         return results;
//     }
    
//     const vector<string>& wordBreak(string s, unordered_set<string>& dict) {
//         // Already in memory, return directly
//         if(mem_.count(s)) return mem_[s];
        
//         // Answer for s
//         vector<string> ans;
        
//         // s in dict, add it to the answer array
//         if(dict.count(s)) 
//             ans.push_back(s);
        
//         for(int j=1;j<s.length();++j) {
//             // Check whether right part is a word
//             const string& right = s.substr(j);
//             if (!dict.count(right)) continue;
            
//             // Get the ans for left part
//             const string& left = s.substr(0, j);
//             const vector<string> left_ans = 
//                 append(wordBreak(left, dict), right);
            
//             // Notice, can not use mem_ here,
//             // since we haven't got the ans for s yet.
//             ans.insert(ans.end(), left_ans.begin(), left_ans.end());
//         }
        
//         // memorize and return
//         mem_[s].swap(ans);
//         return mem_[s];
//     }
// private:
//     unordered_map<string, vector<string>> mem_;
// };

