// 53. Maximum Subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> res(nums.size(),0);
        int max = nums[0];
        res[0] = nums[0];
        
        for (int i=1;i<nums.size();i++) {
            if (res[i-1]<0) {
                res[i] = nums[i];
                if (res[i] > max) {
                    max = res[i];
                }
            }
            else {
                res[i] = res[i-1] + nums[i];
                if (res[i] > max) {
                    max = res[i];
                }
            }
        }
        
        return max;
    }
};
