#include <al_zzh.h>

using namespace std;

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int ans = 0;
        int temp = coins[0];
        if (temp != 1) {
            return 1;
        }
        for (int i = 1; i < coins.size(); i++) {
            if(temp < coins[i] - 1) {
                return temp + 1;
            }
            else temp += coins[i];
        }
        return temp + 1;
    }
};