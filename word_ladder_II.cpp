class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ret_list;
        queue<vector<string>> q;
        int step = 0;
        if (similar(beginWord, endWord)) {
            ret_list.insert(ret_list.begin(), {beginWord, endWord});
            return ret_list;
        }
        sort(wordList.begin(), wordList.end());
        wordList.erase(unique(wordList.begin(), wordList.end()), wordList.end());

        int find_e = 0;
        for (auto i = wordList.begin(); i < wordList.end(); i++) {
            if (*i == beginWord) {
                wordList.erase(i);
            }
            if (*i == endWord) {
                find_e = 1;
            }
        }

        if (find_e == 0) {
            return ret_list;
        }
        
        


        q.push({beginWord});

        while (!q.empty()) {
            int lenq = q.size();
            int end_signal = 0;
            for (int i = 0; i < lenq; i++) {
                // cout << "--------------------------------------"<< endl;
                vector<string> curlist = q.front();
                q.pop();
                string last_curlist = curlist[curlist.size()-1];
                // cout << last_curlist + ": "<< endl;
                if (similar(last_curlist, endWord)) {
                    curlist.insert(curlist.end(), endWord);
                    ret_list.push_back(curlist);
                    end_signal = 1;
                }
                else {
                    if (end_signal == 1) {
                        continue;
                    }
                    else{
                        // for (int j = 0; j < wordList.size(); j++) {

                        //     int used_word = 0;
                        //     for (int k = 0; k < curlist.size(); k++) {
                        //         if (wordList[j] == curlist[k]) {
                        //             used_word = 1;
                        //             break;
                        //         }
                                
                        //     }

                        //     if (used_word == 1) {
                        //         continue;
                        //     }
                            
                        //     if (similar(last_curlist, wordList[j])) {
                        //         // cout << wordList[j] << endl;
                        //         vector<string> temp = curlist;
                        //         temp.insert(temp.end(), wordList[j]);
                        //         q.push(temp);
                        //         // wordList.erase(wordList.begin()+j);
                        //         // j--;
                        //     }
                        // }


                    }

                }

            }


            if (end_signal == 1) {
                return ret_list;
            }
        }

        return ret_list;
        
        
        
        
        
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



/*
    同样单项BFS,还是要根据每一位loop比较快!!!!
    而且一定要用dict unordered_set!!!!!
*/
// class Solution {
//     public:
//     /*
//         The idea is to run a BFS from beginWord to endWord, while keeping track of the path.
//         Once the currWord == endWord, we have found the shortest path.
//         The nextLevel keeps track of all the words reachable from currLevel.
//         All words in nextLevel should be erased from dict to avoid loops.( This is slight modification to the usual BFS ).
    
//     */
//         vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//             unordered_set< string > dict( wordList.begin(), wordList.end() );
//             dict.erase( beginWord );
//             queue< vector< string > > q;
//             vector< vector< string > > result;
//             q.push( { beginWord } );
//             bool found = false;
//             while( !q.empty() ) {
//                 int size = q.size();
//                 unordered_set< string > nextLevel;

//                 for( int i = 0 ; i < size ; ++i ) {
//                     vector< string > currLevel = q.front();
//                     q.pop();
//                     string currWord = currLevel.back();
//                     if( currWord == endWord ) {
//                         found = true;
//                         result.push_back( currLevel );
//                     } else {
//                         for( int i = 0 ; i < currWord.size() ; ++i ) {
//                             char orig = currWord[ i ];
//                             for( char ch = 'a' ; ch <= 'z' ; ++ch ) {
//                                 if( ch == orig ) continue;
//                                 currWord[ i ] = ch;
//                                 if( dict.find( currWord ) != dict.end() ) {
//                                     nextLevel.insert( currWord );
//                                     q.push( currLevel );
//                                     q.back().push_back( currWord );
//                                 }
//                             }
//                             currWord[ i ] = orig;
//                         }
//                     }
//                 }
//                 if( found ) break;
//                 for( auto n : nextLevel ) {
//                     dict.erase( n );
//                 }
//             }
//             return result;
//         }

// };



/*
    最好的算法!

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()), current, next;
        if (dict.find(endWord) == dict.end()) {
            return {};
        }
        unordered_map<string, vector<string>> children;
        vector<vector<string>> ladders;
        vector<string> ladder;
        current.insert(beginWord);
        ladder.push_back(beginWord);
        while (true) {
            for (string word : current) {
                dict.erase(word);
            }
            for (string word : current) {
                findChildren(word, next, dict, children);
            }
            if (next.empty()) {
                break;
            }
            if (next.find(endWord) != next.end()) {
                genLadders(beginWord, endWord, children, ladder, ladders);
                break;
            }
            current.clear();
            swap(current, next);
        }
        return ladders;
    }
private:

    void findChildren(string word, unordered_set<string>& next, unordered_set<string>& dict, unordered_map<string, vector<string>>& children) {
        string parent = word;
        for (int i = 0; i < word.size(); i++) {
            char t = word[i];
            for (int j = 0; j < 26; j++) {
                word[i] = 'a' + j;
                if (dict.find(word) != dict.end()) {
                    next.insert(word);
                    children[parent].push_back(word);
                }
            }
            word[i] = t;
        }
    }

    void genLadders(string beginWord, string endWord, unordered_map<string, vector<string>>& children, vector<string>& ladder, vector<vector<string>>& ladders) {
        if (beginWord == endWord) {
            ladders.push_back(ladder);
        } else {
            for (string child : children[beginWord]) {
                ladder.push_back(child);
                genLadders(child, endWord, children, ladder, ladders);
                ladder.pop_back();
            }
        }
    }
};
 */