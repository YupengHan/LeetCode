class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int>> pq;
        for (int i = 0; i < nums.size(); ++i) {
            pq.push(nums[i]);
            
        }
        k--;
        while (k--) {
            printf("%d\n", pq.top());
            pq.pop();
        }
        return pq.top();
    }
};