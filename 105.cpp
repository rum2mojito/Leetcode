// 105. Construct Binary Tree from Preorder and Inorder Traversal

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    
    TreeNode* build (vector<int>& preorder, vector<int>& inorder, int lp, int rp, int li, int ri) {
        if (lp>rp) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[lp]);
        for (int k=li; k<=ri; k++) {
            if (preorder[lp] == inorder[k]) {
                root -> left = build(preorder, inorder, lp + 1, lp + (k - li), li, k - 1);
                root -> right = build(preorder, inorder, lp + (k - li) + 1, rp, k + 1, ri);
            }
        }
        return root;
    }
};
