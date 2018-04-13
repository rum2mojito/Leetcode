// 563. Binary Tree Tilt

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
    int findTilt(TreeNode* root) {
        if (root) {
            int res = helper(root->left) - helper(root->right);
            res =  res<0? -1*res:res;
            res += findTilt(root->left) + findTilt(root->right);
            return res;
        }
        return 0;
    }
    
    int helper (TreeNode* root) {
        if (root == NULL) return 0;
        return root->val + helper (root->left) + helper (root->right);
    }
};
