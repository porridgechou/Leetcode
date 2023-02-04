#include <al_zzh.h>

using namespace std;

class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == j || (i + j + 1) == row) {
                    if (grid[i][j] == 0) {
                        return false;
                    }
                } else if (grid[i][j]) {
                    return false;
                }
                
            }
        }
        return true;
    }
};