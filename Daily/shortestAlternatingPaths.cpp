#include <al_zzh.h>

using namespace std;

// 0代表红色，1代表蓝色
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // 出边数组初始化
        r = vector<vector<int>> (n);
        b = vector<vector<int>> (n);
        for (auto& re : redEdges) {
            r[re[0]].push_back(re[1]);  // 红色出边数组
        }
        for (auto& be : blueEdges) {
            b[be[0]].push_back(be[1]);  // 蓝色出边数组
        }
        // 答案数组初始化，初始化为-1方便提交以及判断是否已经记录过最短路径
        ans = vector<int> (n, -1);
        bfs(n);
        return ans;
    }
private:
    void bfs(int x) {
        // 搜索从0到x的所有点的最短路径
        queue<vector<int>> q;
        q.push({0, 0, 0});  // 三维数组「颜色」、「点」、「路径长度」，其中0是红色，1是蓝色
        q.push({1, 0, 0});
        while (!q.empty()) {
            auto tmp = q.front();
            q.pop();   
            int color = tmp[0], point = tmp[1], path = tmp[2];
            // 如果到达一个点且ans数组中这个点是-1，则证明没有更新过且可以按规则到达，更新答案
            if (ans[point] == -1) ans[point] = path;
            // 获得目前已经到达点的出边数组
            auto& edges = color ? r[point] : b[point];
            for (auto nextPoint : edges) {
                // 颜色需要反转
                int nextColor = color == 0 ? 1 : 0;
                // 判断point到nextPoint且颜色为nextColor的路径是否使用过，如果使用过则不记录
                if (visit[point][nextPoint][nextColor]) continue;
                // 路径记为true防止成环
                visit[point][nextPoint][nextColor] = true;
                // 下一个点加入到队列中
                q.push({nextColor, nextPoint, path + 1});
            }
        }
    }
    vector<vector<int>> r;  // 红色路径出边数组
    vector<vector<int>> b;  // 蓝色路径出边数组
    vector<int> ans;
    bool visit[100][100][2];    // 路径记录数组，这里的大小根据题意直接写死方便一些
};