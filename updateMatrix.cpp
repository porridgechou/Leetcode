#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    const int dx[4] = {0, 1, -1, 0};
    const int dy[4] = {1, 0, 0, -1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int col = mat.size();
        int row = mat[0].size();
        vector<vector<int>> ans(col, vector<int>(row));
        vector<vector<int>> seen(col, vector<int>(row));
        for (int x = 0; x < mat.size(); x++) {
            for (int y = 0; y < mat[0].size(); y++){
                ans[x][y] = dfx(mat, x, y, seen); 
            }
        }
        return ans;
    }

    int dfx(vector<vector<int>>& mat, int x, int y, vector<vector<int>>& seen){
        if (mat[x][y] == 0) {
            return 0;
        }
        int ans = INT_MAX;
        seen[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int mx = x + dx[i];
            int my = y + dy[i];
            if (mx < 0 || mx >= mat.size() || my >= mat[0].size() || my < 0 || seen[mx][my] == 1) {
                continue;
            }
            seen[mx][my] = 1;
            int des = 1;
            if (mat[mx][my] != 0) {
                des += dfx(mat, mx, my, seen);
            }
            ans = min(ans, des);
        }
        return ans;
    }
};