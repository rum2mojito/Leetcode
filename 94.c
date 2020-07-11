/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    if(root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    int right_nums = 0;
    int left_nums = 0;
    
    int* right = NULL;
    int* left = NULL;
    
    if(root->left != NULL) {
        left = inorderTraversal(root->left, &left_nums);
    }
    if(root->right != NULL) {
        right = inorderTraversal(root->right, &right_nums);
    }
    
    *returnSize = left_nums + 1 + right_nums;
    int *ret = (int*)malloc(sizeof(int) * (left_nums + 1 + right_nums));
    
    for(int i=0; i<left_nums; i++) {
        ret[i] = left[i];
    }
    ret[left_nums] = root->val;
    for(int i=0; i<right_nums; i++) {
        ret[left_nums + 1 + i] = right[i];
    }
    
    if(left != NULL) free(left);
    if(right != NULL) free(right);
    
    return ret;
}
