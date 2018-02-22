// 654. Maximum Binary Tree

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode *p ;
        grow (p,nums);
        
        return p;
    }
    void grow (TreeNode* &root , vector<int> nums){
        int a = maximum(nums);
        root = new TreeNode(a);
        vector<int> L = cut_l(nums , a);
        vector<int> R = cut_r(nums , a);
        if (R.size()!=0)
            grow (root->right , R);
        if (L.size()!=0)
            grow (root->left , L);
    }
    vector<int> cut_l (vector<int> nums , int k) {
        vector<int> res;
        int i=0;
        while (nums[i]!=k){
            res.push_back(nums[i]);
            i++;
        }
        return res;
    }
    vector<int> cut_r (vector<int> nums , int k) {
        vector<int> res;
        int i=nums.size()-1;
        while (nums[i]!=k){
            res.push_back(nums[i]);
            i--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    int maximum (vector<int> nums) {
        int res = -1;
        for (int i=0;i<nums.size();i++){
            if (nums[i]>res){
                res = nums[i];
            }
        }
        return res;
    }
};
