#include <al_zzh.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> track;

    void backtrack(vector<int>& nums, vector<bool> used) {
        if (track.size() == nums.size()) {
            ans.emplace_back(track);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            track.emplace_back(nums[i]);
            used[i] = true;
            backtrack(nums, used);
            track.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size());
        backtrack(nums, used);
        return ans;
    }
};