#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> track;
    
    void backtrace(vector<int>& nums, int n) {
        res.push_back(track);
        for (int i = n; i < nums.size(); i++) {
            track.push_back(nums[i]);
            backtrace(nums, i + 1);
            track.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        backtrace(nums, 0);
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{1,2,3};
    s.subsets(nums);
}