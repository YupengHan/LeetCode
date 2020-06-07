/*
    Can be optimized
*/
// class Solution {
// public:
//     string minRemoveToMakeValid(string s) {
//         int left = 0, right = 0;

//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == '(') {
//                 left++;
//             }
//             if (s[i] == ')') {
//                 if (left > 0) {
//                     left--;
//                 }
//                 else {
//                     s.erase(i,1);
//                     i--;
//                 }
                
//             }
            
            
//         }
        
//         int left = 0, right = 0;
//         for (int i = s.size()-1; i >= 0; i--) {
//             if (s[i] == ')') {
//                 right++;
//             }
//             if (s[i] == '(') {
//                 if (right > 0) {
//                     right--;
//                 }
//                 else {
//                     s.erase(i,1);
//                     i++;
//                 }
                
//             }
            
            
//         }

//         return s;
        
//     }
// };
/*
    更慢了
*/
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // int b = 0;
        queue <int> q;
        unordered_set <int> idx_to_remove;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                // b++;
                q.push(i);
            }
            if (s[i] == ')') {
                if (!q.empty()) {
                    // b--;
                    q.pop();
                }
                else {
                    idx_to_remove.insert(i);
                }           
            }  
        }

        while(!q.empty()) {
            int tmp = q.front();
            idx_to_remove.insert(tmp);
            q.pop();
        }
        
        string ret = "";
        for (int i = 0; i < s.size(); i++) {
            if (!idx_to_remove.count(i)) {
                ret+s[i];
            }
            
        }
        return ret;
        
    }
};