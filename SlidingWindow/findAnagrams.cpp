#include <al_zzh.h>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> need, window;
        for (char c : p) {
            need[c]++;
        }

        int left = 0;
        int right = 0;
        int valid = 0;
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (need[c] == window[c]) {
                    valid++;
                }
            }
            while (right - left >= p.size())
            {
                char d = s[left];
                if (valid == need.size()) {
                    ans.emplace_back(left);
                }
                left++;
                if (need.count(d)) {
                    if (need[d] == window[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        vector<int> ans;
        for (char c : p) {
            need[c]++;
        }
        int left = 0;
        int right = 0;
        int valid = 0;
        while (right < s.size())
        {
            char c = s[right];
            if (need.count(c)) {
                window[c]++;
                if (need[c] == window[c]) {
                    valid++;
                }
            }
            while (right - left + 1 == p.size())
            {
                if (valid == need.size()) {
                    ans.emplace_back(left);
                }
                char d = s[left];
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
        return ans;
    }
};