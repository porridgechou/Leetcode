#include <al_zzh.h>

using namespace std;

class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* nodeX = find (root, x);
        int left = nodeCount(nodeX->left);
        int right = nodeCount(nodeX->right);
        if (left > n / 2) {
            return true;
        }
        if (right > n / 2) {
            return true;
        }

        if (n - left - right - 1 > n / 2) {
            return true;
        }
        return false;
    }

    TreeNode* find(TreeNode* root, int x) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == x) {
            return root;
        }

        if (find(root->left, x) != nullptr) {
            return find(root->left, x);
        }

        if (find(root->right, x) != nullptr) {
            return find(root->right, x);
        }

        return nullptr;
    }

    int nodeCount (TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + nodeCount(root->left) + nodeCount(root->right);
    }
};