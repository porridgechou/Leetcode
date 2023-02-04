#include <al_zzh.h>
#include <ListNode.h>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> nums;
        nums.resize(n);
        Difference df(nums);
        for (auto book : bookings) {
            
        }


    }
};

// 差分数组工具类
class Difference {
public:
    vector<int> diff;

    Difference(vector<int> nums) {
        diff.resize(nums.size());
        diff[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            diff[i] = nums[i] - nums[i-1];
        }
    }
    void increment(int i, int j, int val) {
        diff[i] += val;
        if (j + 1 < diff.size()) {
            diff[j + 1] -= val;
        }
    }

    vector<int> result() {
        vector<int> res(diff.size());
        res[0] = diff[0];
        for (int i = 1; i < diff.size(); i++) {
            res[i] = res[i-1] + diff[i];
        }
        return res;
    }
};
