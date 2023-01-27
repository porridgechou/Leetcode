#include <al_zzh.h>

using namespace std;

// class Solution {
// public:
//     int fib(int n) {
//         if (n == 0) return 0;
//         vector<int> dp(n + 1);
//         dp[0] = 0;
//         dp[1] = 1;
//         for (int i = 2; i <= n; i++) {
//             dp[i] = dp[i -1] + dp[i - 2];
//         }
//         return dp[n];
//     }
// };

class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        int dp_1 = 1;
        int dp_2 = 0;
        for (int i = 2; i <= n; i++) {
            int dp_i = dp_1 + dp_2;
            dp_2 = dp_1;
            dp_1 = dp_i;
        }
        return dp_1;
    }
};