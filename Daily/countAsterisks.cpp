#include <al_zzh.h>

using namespace std;

class Solution {
public:
    int countAsterisks(string s) {
        int ans = 0;
        int flag = 0;
        for (char c : s) {
            if (c == '|' && flag == 0) {
                flag = 1;
            } else if (c == '|' && flag == 1)
            {
                flag = 0;
            }
            if (flag == 0 && c =='*') {
                ans++;
            }
        }
        return ans;
    }
};