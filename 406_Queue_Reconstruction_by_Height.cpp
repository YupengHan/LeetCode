class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Sort by hiehgt
        sort(begin(people), end(people), []
            (const vector<int>& p1, const vector<int>& p2) {
                if (p1[0] != p2[0]) {
                    return (p1[0] < p2[0]);    
                }
                else {
                    return (p1[1] < p2[1]);
                }
            }
        );

        vector<vector<int>> qrh(people.size()); //qrh Queue Reconstruction by Height
        vector<int> empty_idx(people.size());
        for (int i = 0; i < people.size(); ++i) {
            empty_idx[i] = i;
        }

        int prev = -1;
        int same_cnt = 0;
        for (auto p : people) {
            // cout << "[" << p[0] << "," << p[1] << "]";
            
            int rest_idx;
            int qrh_idx;
            if (prev != p[0]) {
                rest_idx = p[1];
                same_cnt = 0;
            }
            else {
                same_cnt++;
                rest_idx = p[1]-same_cnt;
            }
            prev = p[0];

            qrh_idx = empty_idx[rest_idx];
            // cout << " " << qrh_idx;
            qrh[qrh_idx] = p;
            
            if (!empty_idx.empty()){
                // empty_idx.erase(qrh_idx);
                vector<int>::iterator itr = find(empty_idx.begin(), empty_idx.end(), qrh_idx);
                
                if (itr != empty_idx.end()) {
                    // cout << *itr;
                    empty_idx.erase(itr);   
                }
            }
            // cout << endl;
        }

        return qrh;

    }
};



/*
    Vectro Insert at certain location:
    vec.insert(vec.begin()+idx, val);

*/