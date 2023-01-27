#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 广度优先
class Solution {
public:
    const int dx[4] = {0, 1, -1, 0};
    const int dy[4] = {1, 0, 0, -1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int curColor = image[sr][sc];
        if (curColor == color) {
            return image;
        }
        int n = image.size();
        int m = image[0].size();
        queue<pair<int, int>> que;
        que.emplace(sr, sc);
        image[sr][sc] = color;
        while (!que.empty())
        {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++){
                int mx = x + dx[i];
                int my = y + dy[i];
                if (mx >= 0 && mx < n && my < m && my >= 0 && image[mx][my] == curColor){
                    que.emplace(mx, my);
                    image[mx][my] = color;
                }
            }
        }
        return image;
    }
};

// 深度优先

class Solution {
public:
    const int dx[4] = {0, 1, -1, 0};
    const int dy[4] = {1, 0, 0, -1};

    void dfs(vector<vector<int>> &image, int x, int y, int curColor, int color){
        if (image[x][y] == curColor) {
            image[x][y] = color;
            for (int i = 0; i < 4; i++) {
                int mx = x + dx[i];
                int my = y + dy[i];
                if(mx >= 0 && mx < image.size() && my >= 0 && my < image[0].size()){
                    dfs(image, mx, my, curColor, color);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int curColor = image[sr][sc];
        if(curColor != color){
            dfs(image, sr, sc, curColor, color);
        }
        return image;
    }
};