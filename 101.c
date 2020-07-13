/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool __isSymmetric(struct TreeNode* left, struct TreeNode* right) {
    if(right == NULL && left == NULL) return true;
    if(((left && right) == NULL) && (left || right)) return false;
    if(left->val != right->val) return false;
    
    return __isSymmetric(left->left, right->right) && __isSymmetric(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root){
    if(root == NULL) return true;
    
    return __isSymmetric(root->left, root->right);
}
