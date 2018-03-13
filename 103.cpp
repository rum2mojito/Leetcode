// 103. Binary Tree Zigzag Level Order Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if (root)
            q.push(root);
        bfs(res,q,false);
        return res;
    }
    
    void bfs (vector<vector<int>> &res, queue<TreeNode*> q, bool flag) {
        if (q.empty()) {
            return;
        }
        vector<int> rec;
        queue<TreeNode*> q2;
        while (!q.empty()) {
            TreeNode *p = q.front();
            q.pop();
            if (p->left) {
                q2.push(p->left);
            }
            if (p->right) {
                q2.push(p->right);
            }
            rec.push_back(p->val);
        }
        if (flag)
            reverse(rec.begin(),rec.end());
        res.push_back(rec);
        bfs(res,q2,!flag);
    }
};
