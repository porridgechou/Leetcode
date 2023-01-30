#include <al_zzh.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) {
            need[c]++;
        }
        int left = 0;
        int right = 0;
        int valid = 0;
        int start = 0;
        int len = INT_MAX;
        while (right < s.size())
        {
            char c = s[right];
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            while (valid == need.size())
            {
                if (right - left + 1 < len) {
                    len = right - left + 1;
                    start = left;
                }
                char d = s[left];
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
                left++;
            }
            right++;
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};