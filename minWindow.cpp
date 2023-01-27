#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, windows;
        for (char c : t) {
            need[c]++;
        }

        int left = 0;
        int right = 0;
        int value = 0;
        int start = 0;
        int len = INT_MAX;
        while (right < s.size())
        {
            char c = s[right];
            right++;
            if (need.count(c)){
                windows[c]++;
                if (windows[c] == need[c]){
                    value++;
                }
            }

            while (value == need.size())
            {
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                char deleteC = s[left];
                left++;
                if (need.count(deleteC)) {
                    if (windows[deleteC] == need[deleteC]) {
                        value--;
                    }
                    windows[deleteC]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};