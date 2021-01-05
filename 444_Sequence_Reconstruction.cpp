class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if (seqs.empty() && !org.empty()) {
            return false;
        }
        
        if (org.size() == 1) {
            for (auto seq : seqs) {
                if (seq.size()>1) return false;
                if (seq[0] != org[0]) return false;
            }
            return true;
        }
        
        int len = org.size();
        vector<vector<int>> graph(len+1);
        vector<int> inDegree (len+1, 0);
        

        // Build Graph
        for (auto seq : seqs) {
            // for (auto ele:seq) {
            //     if (ele > len+1) return false;
            // }
            for (int i = 0; i < seq.size(); i++) {
                if (seq[i] > len+1) return false;
                if (i ==0) continue;
                // cout << seq[i-1] << " " << seq[i] << " " << i << endl;
                graph[seq[i-1]].push_back(seq[i]);
                inDegree[seq[i]] += 1;
            }
        }

        // May not need
        int idx = 0;
        vector<int> ordering(len);

        queue<int> q;
        for (int i = 1; i <= len; ++i) {
            if (inDegree[i] == 0) {
                // cout << "push " << i << endl;
                q.push(i);
            }
        }

        if (q.size() > 1) {
            cout << 28 << endl;
            return false;
        }

        while(!q.empty()) {
            int at = q.front();
            ordering[idx] = at;
            q.pop();
            idx++;
            // cout << "Ordering: " << at << endl;
            for (auto to : graph[at]) {
                inDegree[to] -= 1;
                if (inDegree[to] == 0) {
                    q.push(to);   
                }
            }
            if (q.size() > 1) {
                cout << 41 << endl;
                return false;
            }
        }

        if (idx != len) {
            cout << 47 << endl;
            cout << idx;
            return false;
        };
        for (int i=0; i < len; i++) {
            if (ordering[i] != org[i]) return false;
        }
        return true;
    }
};