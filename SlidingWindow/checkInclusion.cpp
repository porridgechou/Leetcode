#include <al_zzh.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> need, window;
        for (char c : s1) {
            need[c]++;
        }
        int left = 0;
        int right = 0;
        int valid = 0;
        while (right < s2.size())
        {
            char c = s2[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            while (right - left >= s1.size()) {
                if (valid == need.size()) {
                    return true;
                }
                char d = s2[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return false;
    }
};


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (char c : s1) {
            need[c]++;
        }
        int left = 0;
        int right = 0;
        int valid = 0;
        while (right < s2.size())
        {
            char c = s2[right];
            if (need.count(c)) {
                window[c]++;
                if (need[c] == window[c]) {
                    valid++;
                }
            }
            while (right - left + 1 == s1.size())
            {
                if (valid == need.size()) {
                    return true;
                }
                char d = s2[left];
                if (need.count(d)) {
                    if (need[d] == window[d]) {
                        valid--;
                    }
                    window[d]--;
                }
                left++;
            }
            right++;
        }
        return false;
    }
};
