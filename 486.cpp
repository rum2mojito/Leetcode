// 486. Predict the Winner

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return recur(nums,0,nums.size()-1)>=0? true:false;
    }
    
    int recur (vector<int> nums, int left, int right) {
        if (left == right) return nums[left];
        else {
            return max (nums[left] - recur(nums,left+1,right), nums[right] - recur(nums,left,right-1));
        }
    }
};
