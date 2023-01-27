#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, bool> map;
        for (int num : nums) {
            if(map[num]) {
                return num;
            }
            map[num] = true; 
        }
        return -1;
    } 
};

int main () {
    vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
    Solution Solution;
    cout << Solution.findRepeatNumber(nums);
}