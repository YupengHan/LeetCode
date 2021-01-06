class Solution {

public:
    bool buildGraph(string word1, string word2, unordered_map<char, vector<char>>& Graph, unordered_map<char, int>& In_drgree) {
        int min_cnt = min(word1.size(), word2.size());
        for (int i = 0; i < min_cnt; ++i) {
            if (word1[i] != word2[i]) {
                vector<char> child_toList = Graph[word2[i]];
                Graph[word1[i]].push_back(word2[i]);
                In_drgree[word2[i]] += 1;
                return true;
            }
        }
        if (word1.size() > word2.size()) return false;
        return true;
    }


    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> Graph;
        int char_cnt = 0;
        unordered_map<char, int> In_drgree;
        for (auto word : words) {
            for (auto c : word) {
                if (!In_drgree.count(c)) {
                    char_cnt++;
                    In_drgree[c] = 0;
                }
            }
        }
        // Build Graph
        for (int i = 1; i < words.size(); ++i) {
            if (!buildGraph(words[i-1], words[i], Graph, In_drgree)) return "";
        }

        string ao(char_cnt, '0');
        queue<char> tmp_queue;
        int idx = 0;

        unordered_map<char, int>::iterator iter;
        for (iter = In_drgree.begin(); iter != In_drgree.end(); iter++) {
            if (iter->second == 0) tmp_queue.push(iter->first);
        }
        while(!tmp_queue.empty()) {
            char cur_c = tmp_queue.front();
            tmp_queue.pop();
            ao[idx] = cur_c;
            // cout << ao << endl;
            idx++;
            for (auto to_item : Graph[cur_c]) {
                In_drgree[to_item]--;
                if (In_drgree[to_item] == 0) {
                    tmp_queue.push(to_item);
                }
            }
        }
        if (idx != char_cnt) {
            // cout << idx << endl;
            return "";
        }
        return ao;
    }
};