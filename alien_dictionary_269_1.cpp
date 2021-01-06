// TopoSort DFS
class Solution {
private:
    int unvisit = 0;
    int workon  = 1;
    int visited = 2;
    int detect_cycle = -2;
public:
    bool buildGraph(string word1, string word2, unordered_map<char, vector<char>>& Graph) {
        int min_cnt = min(word1.size(), word2.size());
        for (int i = 0; i < min_cnt; ++i) {
            if (word1[i] != word2[i]) {
                vector<char> child_toList = Graph[word2[i]];

                Graph[word1[i]].push_back(word2[i]);
                return true;
            }
        }
        if (word1.size() > word2.size()) return false;
        return true;
    }



    string alienOrder(vector<string>& words) {
        if (words.size() == 1) return words[0];


        unordered_map<char, vector<char>> Graph;
        int char_cnt = 0;
        unordered_map<char, int> Visited_map;
        for (auto word : words) {
            for (auto c : word) {
                if (!Visited_map.count(c)) {
                    char_cnt++;
                    Visited_map[c] = unvisit;
                }
            }
        }

        // Build Graph
        for (int i = 1; i < words.size(); ++i) {
            if (!buildGraph(words[i-1], words[i], Graph)) return "";
        }
        // Check the Graph Correct Or Not
        // unordered_map<char, vector<char>>::iterator giter;
        // for (giter = Graph.begin(); giter != Graph.end(); giter++) {
        //     cout << giter->first << ": ";
        //     vector<char> to_list;
        //     to_list = giter->second;
        //     for (auto to : to_list) {
        //         cout << to << " ";
        //     }
        //     cout << endl;
        // }

        string ao(char_cnt, '0');
        int idx = char_cnt-1;
        unordered_map<char, int>::iterator vmiter;
        for (vmiter = Visited_map.begin(); vmiter != Visited_map.end(); vmiter++) {
            if (vmiter->second == unvisit) {
                if (!dfs(vmiter->first, ao, idx, Visited_map, Graph)) return "";
            }
        }
        return ao;

        // return "";
    }
    bool dfs(char cur_c, string& ao, int& idx, unordered_map<char, int>& Visited_map,
        unordered_map<char, vector<char>>& Graph) {

        if (Visited_map[cur_c] == workon) {
            return false;
        }
        if (Visited_map[cur_c] == visited) {
            return true;
        }
        
        Visited_map[cur_c] = workon;
        vector<char> to_list = Graph[cur_c];
        for (auto to_item : to_list) {
            if (!dfs(to_item, ao, idx, Visited_map, Graph)) return false;
        }
        Visited_map[cur_c] = visited;
        ao[idx] = cur_c;
        idx--;
        return true;

    }  
};