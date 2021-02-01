class Solution {
private:
    vector<vector<string>> ret;
void mysearch (vector<string>& cur_path, vector<bool>& visited, vector<string>& wordList, string endWord) {
    string cur_word = cur_path[cur_path.size()-1];
    if (cur_word == endWord) {
        ret.push_back(cur_path);
    }
    for (int i = 0; i < wordList.size(); ++i) {
        if (!visited[i]) {
            if (dis(cur_word, wordList[i])) {
                visited[i] = true;
                cur_path.push_back(wordList[i]);
                mysearch(cur_path, visited, wordList, endWord);
                visited[i] = false;
                cur_path.pop_back();    
            }
        }
    }
}
bool dis(string a, string b) {
    // if (a.size() != b.size()) return false;
    int cnt = 0;
    for (int i = 0; i < b.size(); ++i) {
        if (a[i] != b[i]) {
            cnt++;
            if (cnt > 1) return false;
        }
    }
    if (cnt == 1) return true;
    
    // if (cnt > 1) return false;
    
    // cout << "F* ! Same" << endl;
    return false;
}
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        int n = wordList.size();
        vector<bool> visited(n, false);
        bool sige = false;
        bool sigs = false;
        for (int i = 0; i < n; ++i) {
            if (endWord == wordList[i]) {
                sige = true;
                
            }
            if (endWord == wordList[i]) {
                sigs = true;
            }
        }
        if (!sige) return {};
        if (!sigs) return {};

        vector<string> cur_path;
        cur_path.push_back(beginWord);
        for (int i = 0; i < n; ++i) {
            if (beginWord == wordList[i]) {
                visited[i] = true;
                break;
            }
        }
        mysearch(cur_path, visited, wordList, endWord);
        int minsize  = wordList.size();
        for (auto p : ret) {
            if (p.size() < minsize) minsize = p.size();
        }
        vector<vector<string>> result;
        for (auto p : ret) {
            if (p.size() == minsize) {
                result.push_back(p);
            }
        }
        return result;
    }
};




// Try to first build a tree;
// 双枪A*


