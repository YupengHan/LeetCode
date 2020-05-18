// class mystack {
//     int val;
//     mystack *next;
//     mystack(int x) {
//         this->val = x;
//         this=> next = nullptr;
//     }
//     mystack() {
//         this->val = INT_MAX;
//         this=> next = nullptr;
//     }
// };
// class MinStack {
// public:
//     /** initialize your data structure here. */
//     mystack *head; // use this to keep min;
//     MinStack() {
//         head = new mystack();
//     }
    
//     void push(int x) {
        
//     }
    
//     void pop() {
        
//     }
    
//     int top() {
        
//     }
    
//     int getMin() {
        
//     }
// };

// /**
//  * Your MinStack object will be instantiated and called as such:
//  * MinStack* obj = new MinStack();
//  * obj->push(x);
//  * obj->pop();
//  * int param_3 = obj->top();
//  * int param_4 = obj->getMin();
//  */

class MinStack {
public:
    MinStack() {}    
    void push(int x) {
        s.push(x);
        if (v.empty() || v[0] >= x) {
            v.insert(v.begin(), x);
        }
        else {
            v.insert(v.end(), x);
        }
    }    
    void pop() {
        if (s.top() == v[0]) v.erase(v.begin());
        s.pop();
    }  
    int top() {
        return s.top();
    }    
    int getMin() {
        return v[0];
    }
    
private:
    stack<int> s;
    vector<int> v;
};