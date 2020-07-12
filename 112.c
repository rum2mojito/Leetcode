/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool __solution(struct TreeNode* root, int target, int sum) {
	// boundary condition
	if(root == NULL) return false;
    if(root->left == NULL && root->right == NULL) {
        if(target == root->val+sum) return true;
        return false;
    }

    return __solution(root->left, target, sum+root->val) || __solution(root->right, target, sum+root->val);
}



bool hasPathSum(struct TreeNode* root, int sum){
    return __solution(root, sum, 0);
}
