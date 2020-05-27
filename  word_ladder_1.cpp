class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> head, tail;
        int ladder = 2;

        if (dict.find(endWord) == dict.end()) {
            return 0;
        }

        if (similar(beginWord, endWord)) {
            return 2;
        }

        head.push(beginWord);
        tail.push(endWord);
        dict.erase(beginWord);
        dict.erase(endWord);

        while (!head.empty() && !tail.empty()) {

            int hdlen = head.size();
            for (int i = 0; i < hdlen; i++) {
                string curstr = head.front();
                head.pop();

                queue temp_tail = tail;
                for (auto it = dict.begin(); it != dict.end(); ++it) {
                    if (similar(*it, curstr)) {

                        for (int k = 0; k < tail.size(); k++) {
                            string ele_t = temp_tail.front();
                            temp_tail.pop();
                            if (similar(*it, ele_t)) {
                                return ladder++;
                            }
                        }
                        
                        
                        // 没有return,所以是没有链接上
                        head.push(*it);
                        dict.erase(*it);
                        advance(it, -1);

                    }
                }
            }

            
            
            
            swap(head, tail);
            ladder++;
        }

        return 0;
        
        

        
        
    }

    bool similar(string w1, string w2) {
        int cnt = 0;
        for (int i = 0; i < w1.size(); i++) {
            if (w1[i] != w2[i]) cnt++;
        }
        if (cnt == 1) {
            return true;
        }
        return false;

    }
};

// 还是要搞双向的BFS