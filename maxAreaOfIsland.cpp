#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    const int dx[4] = {0, 1, -1, 0};
    const int dy[4] = {1, 0, 0, -1};
    int dfx(vector<vector<int>>& grid, int x, int y){
        int ans = 0;
        if(grid[x][y] == 1) {
            grid[x][y] = 0;
            ans++;
            for(int i = 0; i < 4; i++) {
                int mx = x + dx[i];
                int my = y + dy[i];
                if(mx >= 0 && mx < grid.size() && my >= 0 && my < grid[0].size() && grid[mx][my] == 1){
                    ans += dfx(grid, mx, my);
                }
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                ans = max(ans, dfx(grid, i, j));
            }
        }
        return ans;
    }
};

// 广搜

class Solution {
public:
    const int dx[4] = {0, 1, -1, 0};
    const int dy[4] = {1, 0, 0, -1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int x = 0; x < grid.size(); x++) {
            for(int y = 0; y < grid[0].size(); y++) {
                int cur = 0;
                queue<pair<int, int>> que;
                que.emplace(x, y);
                while (!que.empty())
                {
                    int curX = que.front().first;
                    int curY = que.front().second;
                    que.pop();
                    if (grid[curX][curY] == 1){
                        grid[curX][curY] = 0;
                        cur++;
                        for(int i = 0; i < 4; i++) {
                            int mx = curX + dx[i];
                            int my = curY + dy[i];
                            if(mx >= 0 && mx < grid.size() && my >= 0 && my < grid[0].size() && grid[mx][my] == 1) {
                                que.emplace(mx, my);
                            }
                        }
                    }
                }
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};