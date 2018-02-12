// 637. Average of Levels in Binary Tree

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            queue<TreeNode*> next;
            res.push_back(av(q,next));
            q = next;
        }
        
        return res;
    }
    double av(queue<TreeNode*> q , queue<TreeNode*> &next) {
        TreeNode* p;
        double res = 0;
        int t = q.size();
        while (!q.empty()) {
            p = q.front();
            q.pop();
            if (p->right) {
                next.push(p->right);
            }
            if (p->left) {
                next.push(p->left);
            }
            res += p->val;
        }
        return res/t;
    }
};
