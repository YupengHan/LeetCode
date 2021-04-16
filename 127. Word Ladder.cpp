class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> mySet;
        mySet.insert(beginWord);
        // mySet.push(endWord);
        queue<string> myQueue;
        myQueue.push(beginWord);
        unordered_set <string> wordDict;
        for (auto wd : wordList) {
            wordDict.insert(wd);
        }

        int len = 1;
        while(!myQueue.empty()) {
            len++;
            int count = myQueue.size();
            for (int i = 0; i < count; ++i) {
                string curWord = myQueue.front();
                myQueue.pop();
                for (string nextWord : getNextString(curWord, wordDict)) {
                    if (mySet.find(nextWord) != mySet.end()) {
                        continue;
                    }
                    if (nextWord == endWord) {
                        return len;
                    }

                    mySet.insert(nextWord);
                    myQueue.push(nextWord);
                }

            }
        }
        return 0;

    }
private:
    vector<string> getNextString(string curWord, unordered_set <string>& wordDict) {
        vector<string> nextWords;
        for (int i = 0; i < curWord.size(); ++i) {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (curWord[i] == c) continue;
                string nextWord = curWord;
                nextWord[i] = c;
                if (wordDict.find(nextWord) != wordDict.end()) {
                    nextWords.push_back(nextWord);
                }
            }
        }
        return nextWords;
    }
};