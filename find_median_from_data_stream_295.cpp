// class MedianFinder {
//     vector<int> v;
// public:
//     /** initialize your data structure here. */
//     // MedianFinder() {
        
//     // }
    
//     void addNum(int num) {
//         if (!v.empty()) {
//             v.insert(lower_bound(v.begin(), v.end(), num),num);
//         }
//         else {
//             v.push_back(num);
//         }
//     }
    
//     double findMedian() {
//         int len = v.size();
//         return len & 1 ? v[len/2] :  (v[len/2] + v[len/2 -1]) * 0.5;
//     }
// };

// /**
//  * Your MedianFinder object will be instantiated and called as such:
//  * MedianFinder* obj = new MedianFinder();
//  * obj->addNum(num);
//  * double param_2 = obj->findMedian();
//  */

class MedianFinder {
private:
    priority_queue<int> lo; // 从lo[0]最大
    priority_queue<int, vector<int>, greater<int>> hi; // 从hi[0]最小
    // bool odd_;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        // odd_ = false;
    }
    
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

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */