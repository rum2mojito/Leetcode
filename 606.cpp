606. Construct String from Binary Tree

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
    string tree2str(TreeNode* t) {
        string res;
        if (t) {
            string s;
            stringstream ss;
            ss << t->val;
            ss >> s;
            res += s;
            if (t->right || t->left)
                dfs (res , t->left);
            if (t->right)
                dfs (res , t->right);
        }
        
        return res;
    }
    
    void dfs (string &res , TreeNode* root) {
        res += '(';
        if (root != NULL) {
            string s;
            stringstream ss;
            ss << root->val;
            ss >> s;
            res += s;
            if (root->right || root->left)
                dfs (res , root->left);
            if (root->right)
                dfs (res , root->right);
        }
        
        res += ')';
    }
};
