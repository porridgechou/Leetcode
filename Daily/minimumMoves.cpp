#include <al_zzh.h>

using namespace std;

#define RIGHT 0
#define DOWN 1
typedef pair<int, int> pii;

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int step = 0;
        queue<pii> qu;
        int dp[100][100][2];
        
        /*intial*/
        memset(dp,0,sizeof(dp));
        dp[0][1][RIGHT] = 1;
        qu.push(make_pair(1,RIGHT));
        
        while(!qu.empty()){
            int sz = qu.size();
            
            for(int i = 0;i < sz; ++i){
                pii curr = qu.front();
                qu.pop();
                int x = curr.first/c;
                int y = curr.first%c;
                int d = curr.second;
                
                if( x == r-1 && y == c-1 && d == RIGHT){
                    return step;
                }
                
                if(d == RIGHT){
                    /*right*/
                    if(y < c-1 && grid[x][y+1] != 1){
                        if(!dp[x][y+1][RIGHT]){
                            dp[x][y+1][RIGHT] = 1;
                            qu.push(make_pair(x*c+y+1,RIGHT));
                        }
                    }
                    /*down*/
                    if(x < r-1 && grid[x+1][y-1] == 0 && grid[x+1][y] == 0){
                        if(!dp[x+1][y][RIGHT]){
                            dp[x+1][y][RIGHT] = 1;
                            qu.push(make_pair((x+1)*c+y,RIGHT));
                        }
                        if(!dp[x+1][y-1][DOWN]){
                            dp[x+1][y-1][DOWN] = 1;
                            qu.push(make_pair((x+1)*c+y-1,DOWN));
                        }
                    }
                }else if(d == DOWN){
                    /*down*/
                    if(x < r-1 && grid[x+1][y] != 1){
                        if(!dp[x+1][y][DOWN]){
                            dp[x+1][y][DOWN] = 1;
                            qu.push(make_pair((x+1)*c+y,DOWN));
                        } 
                    }
                    /*right*/
                    if(y < c-1 && grid[x-1][y+1] == 0 && grid[x][y+1] == 0){
                        if(!dp[x][y+1][DOWN]){
                            dp[x][y+1][DOWN] = 1;
                            qu.push(make_pair(x*c+y+1,DOWN));
                        } 
                        if(!dp[x-1][y+1][RIGHT]){
                            dp[x-1][y+1][RIGHT] = 1;
                            qu.push(make_pair((x-1)*c+y+1,RIGHT));
                        } 
                    }
                }
            }
            step++;
        }
        
        return -1;
    }
};




class Solution1 {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<array<int, 2>>> dist(n, vector<array<int, 2>>(n, {-1, -1}));
        dist[0][0][0] = 0;
        queue<tuple<int, int, int>> q;
        q.emplace(0, 0, 0);

        while (!q.empty()) {
            auto [x, y, status] = q.front();
            q.pop();
            if (status == 0) {
                // 向右移动一个单元格
                if (y + 2 < n && dist[x][y + 1][0] == -1 && grid[x][y + 2] == 0) {
                    dist[x][y + 1][0] = dist[x][y][0] + 1;
                    q.emplace(x, y + 1, 0);
                }
                // 向下移动一个单元格
                if (x + 1 < n && dist[x + 1][y][0] == -1 && grid[x + 1][y] == 0 && grid[x + 1][y + 1] == 0) {
                    dist[x + 1][y][0] = dist[x][y][0] + 1;
                    q.emplace(x + 1, y, 0);
                }
                // 顺时针旋转 90 度
                if (x + 1 < n && y + 1 < n && dist[x][y][1] == -1 && grid[x + 1][y] == 0 && grid[x + 1][y + 1] == 0) {
                    dist[x][y][1] = dist[x][y][0] + 1;
                    q.emplace(x, y, 1);
                }
            }
            else {
                // 向右移动一个单元格
                if (y + 1 < n && dist[x][y + 1][1] == -1 && grid[x][y + 1] == 0 && grid[x + 1][y + 1] == 0) {
                    dist[x][y + 1][1] = dist[x][y][1] + 1;
                    q.emplace(x, y + 1, 1);
                }
                // 向下移动一个单元格
                if (x + 2 < n && dist[x + 1][y][1] == -1 && grid[x + 2][y] == 0) {
                    dist[x + 1][y][1] = dist[x][y][1] + 1;
                    q.emplace(x + 1, y, 1);
                }
                // 逆时针旋转 90 度
                if (x + 1 < n && y + 1 < n && dist[x][y][0] == -1 && grid[x][y + 1] == 0 && grid[x + 1][y + 1] == 0) {
                    dist[x][y][0] = dist[x][y][1] + 1;
                    q.emplace(x, y, 0);
                }
            }
        }

        return dist[n - 1][n - 2][0];
    }
};
