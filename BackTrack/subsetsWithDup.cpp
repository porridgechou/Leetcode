#include <al_zzh.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> trace;
    void backtrace(vector<int>& nums, int start) {
        ans.emplace_back(trace);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            trace.emplace_back(nums[i]);
            backtrace(nums, i + 1);
            trace.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrace(nums, 0);
        return ans;
    }
};