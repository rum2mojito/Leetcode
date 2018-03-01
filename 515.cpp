// 515. Find Largest Value in Each Tree Row

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        queue<TreeNode*> q;
        
        res.push_back(root->val);
        if (root->left) {
            q.push(root->left);
        }
        if (root->right) {
            q.push(root->right);
        }
        max_val(q,res);
        
        return res;
    }
    
    void max_val (queue<TreeNode*> &q , vector<int> &res) {
        if (q.empty()) {
            return;
        }
        queue<TreeNode*> q2;
        int max = INT_MIN;
        
        while (!q.empty()) {
            TreeNode *t = q.front();
            q.pop();
            if (t->val > max) {
                max = t->val;
            }
            if (t->left) {
                q2.push(t->left);
            }
            if (t->right) {
                q2.push(t->right);
            }
        }
        
        res.push_back(max);
        max_val(q2,res);
    }
};
