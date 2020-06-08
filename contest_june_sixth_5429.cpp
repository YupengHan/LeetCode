class mycompare{
public:
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if (a.first != b.first) {
            return a.first > b.first;
        }
        else {
            return a.second > b.second;
        }
        
    }
};
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        for (int i = 0; i < arr.size(); i++) {
            addNum(arr[i]);
        }
        double m = findMedian();
        cout << m << endl;
        for (int i = 0; i < arr.size(); i++) {
            int tmp = arr[i];
            st.push(make_pair(abs(tmp-m), tmp));
        }

        vector<int> ret;
        for (int i = 0; i < k; i++) {
            pair<int, int> cur = st.top();
            ret.insert(ret.end(),cur.second);
            st.pop();
        }
        return ret;
        
    }


private:
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycompare> st; // st[0]最大, first: abs(v-m), second: v





    priority_queue<int> lo; // 从lo[0]最大
    priority_queue<int, vector<int>, greater<int>> hi; // 从hi[0]最小
    void addNum(int num) {
        // odd_ = !odd_;
        if (lo.empty() || num <= lo.top()) {
            lo.push(num);
        } else {
            hi.push(num);
        }

        if (lo.size() < hi.size()) {
            lo.push(hi.top());
            hi.pop();
        } else if (lo.size() - hi.size() == 2){
            hi.push(lo.top());
            lo.pop();
        }
        // cout << "low_size: " << lo.size() << "; hi.size: " << hi.size() << endl;
    }
    
    double findMedian() {
        if ((lo.size() + hi.size()) & 1) {
            return lo.top();
        }
        else {
            return (hi.top() + lo.top())*0.5;
        }
    }
};