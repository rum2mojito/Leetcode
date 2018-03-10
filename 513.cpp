// 513. Find Bottom Left Tree Value

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
    int findBottomLeftValue(TreeNode* root) {
        int result = root->val;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode* temp;
        while (!q.empty()) {
            int size = q.size();
            result = q.front()->val;
            while (size--) {
                temp = q.front();
                q.pop();
                if (temp->left != NULL) q.push(temp->left);
                if (temp->right != NULL) q.push(temp->right);
            }
        }
        return result;
    }
};
