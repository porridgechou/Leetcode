#include <al_zzh.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> track;
    void backtrack(int start, int n, int k) {
        if (track.size() == k){
            ans.emplace_back(track);
            return;
        }
        for (int i = start; i <= n; i++) {
            track.emplace_back(i);
            backtrack(i + 1, n, k);
            track.pop_back();
        }
    }    

    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return ans;
    }
};