class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int>> mMap;
        for (auto i : items) {
            mMap[i[0]].push(i[1]);
        }
        vector<vector<int>> ret;
        for (auto it : mMap) {
            int stuId = it.first;
            auto nums = it.second;
            int cSum = 0;
            for (int i = 0; i < 5; ++i) {
                cSum += nums.top();
                nums.pop();
            }
            ret.push_back({stuId, cSum/5});

        }
        return ret;
    }
};

// class Solution {
// public:
//     vector<vector<int>> highFive(vector<vector<int>>& items) {
//         map<int, priority_queue<int>> allScores;
//         for (const auto &item: items) {
//             int id = item[0];
//             int score = item[1];
//             // Add score to the max heap
//             allScores[id].push(score);
//         }
//         vector<vector<int>> solution;
//         for (auto &[id, scores] : allScores) {
//             int sum = 0;
//             // obtain the top k scores (k = 5)
//             for (int i = 0; i < 5; ++i) {
//                 sum += scores.top();
//                 scores.pop();
//             }
//             solution.push_back({id, sum / 5});
//         }
//         return solution;
//     }
// };