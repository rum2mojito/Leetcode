// 538. Convert BST to Greater Tree

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
    TreeNode* convertBST(TreeNode* root) {
        dfs (root,0);
        return root;
    }
    
    int dfs (TreeNode* root, int sum) {
        if (root == NULL) {
            return NULL;
        }
        if (root->right) {
            sum = dfs(root->right,sum);
        }
        root->val += sum;
        sum = root->val;
        if (root->left) {
            sum = dfs(root->left,sum);
        }
        return sum;
    }
};
