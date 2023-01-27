#include <al_zzh.h>

using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> q;
        q.emplace(root);
        int depth = 1;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left == nullptr && cur->right == nullptr) {
                    return depth;
                }
                if (cur->left != nullptr) {
                    q.emplace(cur->left);
                }
                if (cur->right != nullptr) {
                    q.emplace(cur->right);
                }
            }
            depth++;
        }
        return depth;
    }
};