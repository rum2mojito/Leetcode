// 230. Kth Smallest Element in a BST

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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res (0);
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* p;
        while (res.size() != k) {
            p = st.top();
            if (p->left) {
                st.push(p->left);
                p->left = NULL;
            }
            else {
                st.pop();
                res.push_back(p->val);
                if (p->right) {
                    st.push(p->right);
                    p->right = NULL;
                }
            }
        }
        return res[k-1];
    }
};
