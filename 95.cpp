// 95. Unique Binary Search Trees II

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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            vector<TreeNode*> res;
            return res;
        }
        return genBST (1,n);
    }
    
    vector<TreeNode*> genBST (int min , int max) {
        vector<TreeNode *> res;
        if(min>max) {
            res.push_back(NULL);
            return res;
        }
        
        for(int i=min; i<=max; i++) {
            vector<TreeNode*> leftSubTree = genBST(min,i-1);
            vector<TreeNode*> rightSubTree = genBST(i+1,max);
            for(int j=0; j<leftSubTree.size(); j++) {
                for(int k=0; k<rightSubTree.size(); k++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftSubTree[j];
                    root->right = rightSubTree[k];
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
};
