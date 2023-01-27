#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> value;
        for (int i = 0; i < order.size(); i++) {
            value[order[i]] = i;
        }
        sort(s.begin(), s.end(), [&](char a, char b){
            return value[a] < value[b];
        });
        return s;
    }
};

int main() {
    Solution solution;
    string order = "cbafg"; 
    string s = "abcd";
    cout << solution.customSortString(order, s);

}