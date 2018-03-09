// 655. Print Binary Tree

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
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root,0);
        int size = pow(2,h)-1;
        vector<vector<string>> res(h,vector<string>(size,""));
        if (root) {
            bfs_divide (res, root, 0, 0, size-1);
        }
        if (root == NULL) {
            vector<vector<string>> res2(1,vector<string>(1,"None"));
            return res2;
        }
        return res;
    }
    
    void bfs_divide (vector<vector<string>> &res, TreeNode* root, int level, int low, int high) {
        int mid = (low+high)/2;
        if (root->left) {
            bfs_divide (res, root->left, level+1, low, mid-1);
        }
        if (root->right) {
            bfs_divide (res, root->right, level+1, mid+1, high);
        }
        stringstream ss;
        string s;
        ss << root->val;
        ss >> s;
        res[level][mid] = s;
    }
    
    int height (TreeNode* root , int h){
        if (root)
            return max(h+1, max(height(root->left,h+1), height(root->right,h+1)));
        else
            return h;
    }
};
