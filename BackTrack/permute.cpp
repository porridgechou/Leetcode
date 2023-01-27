#include <al_zzh.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    void backtrack(vector<int>& nums, vector<int>& path, vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.emplace_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            path.emplace_back(nums[i]);
            used[i] = true;
            backtrack(nums, path, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size());
        vector<int> path;
        backtrack(nums, path, used);
        return res;
    }
};