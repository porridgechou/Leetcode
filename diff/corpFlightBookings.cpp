#include <al_zzh.h>
#include <ListNode.h>
using namespace std;

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

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> nums;
        nums.resize(n);
        Difference df(nums);
        for (auto book : bookings) {
            df.increment(book[0] - 1, book[1] - 1, book[2]);
        }
        return df.result();
    }
};


int main() {
    Solution s;
    vector<vector<int>> bookings = {{1,2,10},{2,3,20},{2,5,25}};
    int n = 5;
    s.corpFlightBookings(bookings, 5);
}

