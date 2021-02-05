// // /*
// //     Brutal Force 失败
// // */
// // class Solution {
// // public:
// //     bool checkstr(string s) {
// //         int l =0, r = s.size()-1;
// //         while(l<r) {
// //             if (s[l] != s[r]) {
// //                 return false;
// //             }
// //             l++;
// //             r--;
// //         }
// //         return true;
// //     }
// //     vector<vector<int>> palindromePairs(vector<string>& words) {
// //         vector<vector<int>> ret;
// //         for (int i = 0; i < words.size(); ++i) {
// //             for (int j = 0; j < words.size(); ++j) {
// //                 if (j == i) {
// //                     continue;
// //                 }
// //                 if (words[i] == "" || words[j] == "") {
// //                     if (checkstr(words[i]+words[j])) {
// //                         ret.push_back({i,j});
// //                     }
// //                 }
// //                 else {
// //                     if (words[i][0] == words[j][words[j].size()-1]) {
// //                         if (checkstr(words[i]+words[j])) {
// //                             ret.push_back({i,j});
// //                         }
// //                     }
// //                 }
                
// //             }
// //         }
// //         return ret;
// //     }
// // };


// /*
//     学了一个新的数据机构是prefix tree
//     可以给每一个node增加一个vector<int> 代表后面那些属于parlidrome

//     还有一个方法，把child不是char，而是string，把所有可能都定义成一个child。

// */


// /* 遇到的问题是！ c++ new 到底是他大爷的什么东西！
//     new 不仅可以malloc空间，还可以自动调用struct和class的构造函数
// */ 

// class Solution {
// struct trienode {
//     unordered_map<char, trienode*> children;
//     bool endnode;
//     vector<int> palist;
//     trienode() : children(), endnode(false), palist() {}
// };
// public:
//     vector<vector<int>> palindromePairs(vector<string>& words) {
//         root = new trienode;
//         int keep_empty = -1;
//         for (int i = 0; i < words.size(); ++i) {
//             cout << words[i] << ": ";
//             if (words[i] == "") {keep_empty = i;}
//             trienode *cur = root;
//             string nw = words[i];
//             reverse(nw.begin(), nw.end());
//             for (int j = 0; j < nw.size(); ++j) {
//                 // cout << nw[j] << " ";
//                 if (cur->children.count(nw[j]) == 0) {
//                     cur->children[nw[j]] = new trienode();
//                 }
//                 cout << nw.substr(j, nw.size()-j) << " ";
//                 // cout << checkparl(nw.substr(j+1, nw.size()-j)) << " ";
                
//                 if (checkparl(nw.substr(j, nw.size()-j))) {
//                     cur->palist.push_back(i);
//                     cout << "(" << i << ") ";
//                 }
//                 cout << "nw[j]: " << nw[j] << endl;
//                 cur = cur->children[nw[j]];
//             }
//             cur->endnode = true;
//             cur->palist.push_back(i);
//             cout << "(" << i << ") ";
//             cout << endl;
//         }
//         cout << " --------------------- " << endl;
//         vector<vector<int>> ret;
//         for (int i = 0; i < words.size(); ++i) {
//             cout << words[i] << ": ";

//             trienode *cur = root;
//             bool completeI = true;
//             for (auto c : words[i]) {
//                 cout << c << " ";
//                 if (cur->children.count(c) == 0) {
//                     completeI = false;
//                     break;
//                 }
//                 cur = cur->children[c];
//             }
//             if (completeI && cur->palist.size() != 0) {
//                 for (auto j : cur->palist) {
//                     cout << j << " ";
//                     if (i!=j) {
//                         ret.push_back({i,j});   
//                         cout << "("<< i << " " << j << ") "; 
//                     }
//                 }
//             }
//             cout << endl;
//         }
//         if (keep_empty != -1) {
//             for (int i = 0; i < words.size(); ++i) {
//                 if (checkparl(words[i]) && i != keep_empty) {
//                     ret.push_back({i,keep_empty});
//                 }
//             }
//         }
//         // cout << " --------------------- " << endl;
//         // for (auto ii : root->palist) {
//         //     cout << ii << " ";
//         // }
//         // cout << endl;
        
//         return ret;
//     }
// private:
//     trienode* root;
//     bool checkparl(string s) {
//         // if (s.size() == 0) return true;
//         int l = 0, r = s.size()-1;
//         while(l<r) {
//             if (s[l] != s[r]) {
//                 return false;
//             }
//             l++;
//             r--;
//         }
//         return true;
//     }
// };



class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>res;
        buildTrie(words);
        for(int i = 0; i < words.size(); i++){
            string s = words[i];
            for(auto x: Trie[s]) if(isPalindrome(x.first) && i != x.second) res.push_back({i, x.second});
            for(int j = 0; j <= s.size(); j++)
                if(m.count(s.substr(0, j)) && isPalindrome(s.substr(j)) && i != m[s.substr(0, j)]) 
                    res.push_back({i, m[s.substr(0, j)]});
        }    
        return res;
    }
    
private:
    unordered_map<string, vector<pair<string, int> > >Trie;
    unordered_map<string, int>m;
    void buildTrie(vector<string>& words){
        for(int i = 0; i < words.size(); i++){
            string s = words[i];
            reverse(s.begin(), s.end());
            m[s] = i;
            for(int j = 0; j < s.size(); j++) Trie[s.substr(0, j)].push_back({s.substr(j), i});
        }
    }
    
    bool isPalindrome(string s){
        int i = 0, j = s.size() - 1;
        while(i < j) if(s[i++] != s[j--]) return false;
        return true;
    }
};



























