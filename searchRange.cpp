#include <vector>

using namespace std;

class Solution {
public:
    int left_bound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] == target) {
                right = mid - 1;
            }
        }
        if (left == nums.size()) {
            return -1;
        }

        return nums[left] == target ? left : -1;
    }

    int right_bound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] == target) {
                left = mid + 1;
            }
        }
        if (left - 1 < 0) {
            return -1;
        }

        return nums[left - 1] == target ? (left - 1) : -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return vector<int> {left_bound(nums, target), right_bound(nums, target)};
    }
};



    int left_bound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target)
            {
                right = mid;
            }
            return left;
        }
        
    }