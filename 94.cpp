// 94. Binary Tree Inorder Traversal

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()) {
            TreeNode *p = st.top();
            if (p->left != NULL) {
                st.push(p->left);
                p->left = NULL;
            }
            else {
                st.pop();
                res.push_back(p->val);
                if (p->right != NULL) {
                    st.push(p->right);
                    p->right = NULL;
                }
            }
        }
        
        return res;
    }
};
