#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        queue<Node*> que;
        que.emplace(root);
        while (!que.empty())
        {
            int n = que.size();
            for (int i = 0; i < n; i++){
                Node* curNode = que.front();
                que.pop();
                if (i < n - 1){
                    curNode->next = que.front();
                }
                if (curNode->left != nullptr){
                    que.emplace(curNode->left);
                }
                if (curNode->right != nullptr){
                    que.emplace(curNode->right);
                }
            }
        }
        return root;
    }
};