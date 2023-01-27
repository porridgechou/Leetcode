#include <al_zzh.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> track;
    int sum = 0;
    void backtrack(vector<int>& candidates, int target, int start) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            ans.emplace_back(track);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i -1]) {
                continue;
            }
            track.emplace_back(candidates[i]);
            sum += candidates[i];
            backtrack(candidates, target, i + 1);
            track.pop_back();
            sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return ans;
    }
};