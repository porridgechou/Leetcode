#include <al_zzh.h>
#include <ListNode.h>
using namespace std;

class NumArray {
public:
    vector<int> preSum;
    NumArray(vector<int>& nums) {
        preSum.emplace_back(0);
        for (int i = 1; i < nums.size(); i++) {
            preSum.emplace_back(preSum[i] + nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        return preSum[right + 1] - preSum[left];
    }
};