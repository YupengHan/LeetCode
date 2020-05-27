// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         vector<string> left = {beginWord};
//         vector<string> right = {endWord};
        
//         int signal = 0;
//         for (int i = 0; i < wordList.size(); i++) {
//             if (wordList[i] == endWord) {
//                 signal = 1;
//                 wordList.erase(wordList.begin()+i);
//                 break;
//             }
            
//         }
//         if (signal == 0) {
//             return 0;
//         }
        
//         queue
        
        
//         signal = 1;
//         while (signal) {
//             signal = 0;
//             for (int i = 0; i < wordList.size(); i++) {
//                 if (similar(left[0], wordList[i])) {
//                     cout << "left " << wordList[i] << " " << left.size()+right.size() << endl;
//                     left.insert(left.begin(), wordList[i]);
//                     wordList.erase(wordList.begin()+i);
//                     signal = 1;
//                 }
//                 else if (similar(right[0], wordList[i])) {
//                     cout << "right " << wordList[i] << " " << left.size()+right.size() << endl;
//                     right.insert(right.begin(), wordList[i]);
//                     wordList.erase(wordList.begin()+i);
//                     signal = 1;
//                 }

//                 for (int i = 0; i < right.size(); i++) {
//                     if (similar(left[0], right[i])) {
//                         return left.size()+right.size()-i;
//                     } 
//                 }
//                 for (int i = 0; i < left.size(); i++) {
//                     if (similar(left[i], right[0])) {
//                         return left.size()-i+right.size();
//                     }
//                 }
//             }
//         }
        

//         return 0;
//     }

//     bool similar(string w1, string w2) {

//         int cnt = 0;
//         for (int i = 0; i < w1.size(); i++) {
//             if (w1[i] != w2[i]) cnt++;
//         }
//         if (cnt == 1) {
//             return true;
//         }
//         return false;

//     }
// };

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (similar(beginWord, endWord)) {
            return 2;
        }
        
        int signal = 0;
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == endWord) {
                signal = 1;
                break;
            }
        }
        if (signal == 0) {
            return 0;
        }


        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == beginWord) {
                wordList.erase(wordList.begin()+i);
            }   
        }

        sort(wordList.begin(), wordList.end());
        wordList.erase(unique(wordList.begin(), wordList.end()), wordList.end());
        

        queue<string> q;
        q.push(beginWord);
        int step = 1;
        while (!q.empty()) {
            
            step++;
            int k = q.size(); // number of element in this level
            // cout << "size of q: " << k << "; step: "<< step << endl;
            for (int i = 0; i < k; i++) {
                string temp_str = q.front();
                q.pop();
                cout << temp_str << endl;
                cout << "---------" << wordList.size() << "----------" << endl;
 
                for (int j = 0; j < wordList.size(); j++) {
                    cout << j << ": " << wordList[j] << " ";
                    if (similar(wordList[j], temp_str)) {
                        if (wordList[j] == endWord) {
                            return step;
                        }
                        else {
                            q.push(wordList[j]);
                            cout << "pushed!!!" << endl;
                            wordList.erase(wordList.begin()+j);
                            j--;
                        }
                    }
                }


                // 下面这个这个方法也太慢了,单项BFS就是不行
                // dict.erase(temp_str);
                // for (int j = 0; j < temp_str.size(); j++) {
                //     char c = temp_str[j];
                //     for (int k = 0; k < 26; k++) {
                //         temp_str[j] = 'a' + k;
                //         if (dict.find(temp_str) != dict.end()) {
                //             if (temp_str == endWord) return step;
                //             else {
                //                 q.push(temp_str);    
                //             }
                            
                //         }
                //      }
                //     temp_str[j] = c;
                // }
                
                
                
                cout << endl;

            }

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


// Notes:
// 1 What is BFS: 基于层数的queue

// q.push(start)
// step = 0

// while not q.empty():
//     ++ step
//     size = q.size()
//     while size > 0:
//         node = q.pop()
//         next_level_new_node = expand(node)
//         if goal in next_level_new_node: return step + 1
//         q.append(next_level_new_node)

// return not_fund

// // 2 双向BFS
// s1.insert(start)
// s2.insert(end)

// while not (s1.empty() || s2.empty()) {
//     ++step
//     swap*(s1, s2)
//     s = {}
//     for node in s1:
//         new_nodes = expand(node)
//         if any(new_nodes) in s2: return step +1
//     s.append(new_node)
// }
// return not_fund


