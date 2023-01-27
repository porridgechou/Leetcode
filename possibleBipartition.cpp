#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool dfx(int curndoe, int nowcolor, vector<int>& color, const vector<vector<int>>& g){
        color[curndoe] = nowcolor;
        for(auto& nextnode : g[curndoe]){
            if(color[nextnode] == 1 && color[curndoe] == color[nextnode]){
                return false;
            }
            if(color[nextnode] == 0 && !dfx(nextnode, 3^nowcolor, color, g)){
                return false;
            }
        }
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

    }
};