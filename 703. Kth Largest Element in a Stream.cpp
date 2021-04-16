// class KthLargest {
// public:
//     vector<int> myNum;
//     int mK;
//     KthLargest(int k, vector<int>& nums) {
//         myNum.insert(myNum.end(), nums.begin(), nums.end());
//         sort(myNum.begin(), myNum.end());
//         mK = k;
//     }
    
//     int add(int val) {
//         vector<int>::iterator pos = lower_bound(myNum.begin(), myNum.end(), val);
//         // cout << pos - myNum.begin() << endl;
//         myNum.insert(pos, val);
//         return myNum[myNum.size()-mK];
//     }
// };

// /**
//  * Your KthLargest object will be instantiated and called as such:
//  * KthLargest* obj = new KthLargest(k, nums);
//  * int param_1 = obj->add(val);
//  */



class KthLargest {
public:
    struct cmp {
        bool operator() (const int &a, const int &b) {
            return a > b;
        }
    };
    priority_queue<int, vector<int>, cmp> pq;
    KthLargest(int k, vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size()-1; i >= nums.size()-k; --i) {
            pq.push(nums[i]);
        }
    }
    
    int add(int val) {
        if (pq.empty()) {
            pq.push(val);
        }
        if (val > pq.top()) {
            pq.pop();
            pq.push(val);
            return pq.top();
        }

        return pq.top();
    }
};



/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */



class KthLargest {
private: 
    int k = 0; 
    priority_queue<int, vector<int>, greater<int>> pq; // min heap 
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k; 
        for (auto& x : nums) {
            pq.push(x); 
            if (pq.size() > k) 
                pq.pop(); 
        }
    }
    
    int add(int val) {
        pq.push(val); 
        if (pq.size() > k) 
            pq.pop();
        return pq.top(); 
    }
};