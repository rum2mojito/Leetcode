// 238. Product of Array Except Self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        int imm = 1;
        int imm2 = 1;
        int flag = 0;
        
        for (int i=0;i<nums.size();i++) {
            if (nums[i] != 0)
                imm *= nums[i];
            else {
                flag++;
            }
            imm2 *= nums[i];
        }
        
        for (int i=0;i<nums.size();i++) {
            if (nums[i] != 0)
                res[i] = (imm2/nums[i]);
            else {
                if (flag<2) {
                    res[i] = (imm);
                }
            }
        }
        
        return res;
    }
};
