class Solution {
private:
vector<int> ws; 
public:
    Solution(vector<int>& w) {
        int cn = 0;
        for (int i = 0; i < w.size(); ++i) {
            cn += w[i];
            cout << cn << endl;
            ws.push_back(cn);
        }
    }
    
    int pickIndex() {
        int seed = (rand() % ws.back()) + 1;
        // int seed = (rand() % ws.back());
        cout << seed <<endl;
        return lower_bound(ws.begin(), ws.end(), seed) - ws.begin();
    }
};