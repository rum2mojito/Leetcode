/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL) return true;
    if(p == NULL || q == NULL) return false;
    if(p->val != q->val) return false;
    
    bool left = true;
    bool right = true;
    if(p->left != NULL || q->left != NULL) {
        if(p->left == NULL) return false;
        if(q->left == NULL) return false;
        left = isSameTree(p->left, q->left);
    }
    if(p->right != NULL || q->right != NULL) {
        if(p->right == NULL) return false;
        if(q->right == NULL) return false;
        right = isSameTree(p->right, q->right);
    }
    
    return left & right;
}
