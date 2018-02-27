// 687. Longest Univalue Path

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
    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL) return 0;
        int val = root->val;
        int res = 0;
        
        if (root->left && root->left->val == val) {
            res = 1+dfs(root->left);
        }
        if (root->right && root->right->val == val) {
            res += 1+dfs(root->right);
        }
        
        return max(res , max(longestUnivaluePath(root->right) , longestUnivaluePath(root->left)));
    }
    
    int dfs (TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int val = root->val;
        int res = 0;
        
        if (root->left && root->left->val == val) {
            res = 1+dfs(root->left);
        }
        if (root->right && root->right->val == val) {
            res = max(1+dfs(root->right),res);
        }
        
        return res;
    }
};
