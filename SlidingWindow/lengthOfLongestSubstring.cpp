#include <al_zzh.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int left = 0;
        int right = 0;
        unordered_map<char, int> window;
        while (right < s.size())
        {
            char c = s[right];
            window[c]++;
            while (window[c] > 1)
            {
                char d = s[left];
                left++;
                window[d]--;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};