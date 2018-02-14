// 485. Max Consecutive Ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0 , j;
        bool flag = false;
        for (int i=0;i<nums.size();i++) {
            if (nums[i] == 1 && !flag) {
                flag = true;
                j = i;
            }
            if (nums[i] != 1 && flag) {
                flag = false;
                if (i-j>max) {
                    max = i-j;
                }
            }
        }
        if (flag && nums.size()-j>max) {
            max = nums.size()-j;
        }
        return max;
    }
};
