// 565. Array Nesting

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0;
        for (int i=0;i<nums.size();i++) {
            int position = nums[i];
            int step = 1;
            while (position != i && -1 != position) {
                step++;
                int k = position;
                position = nums[position];
                nums[k] = -1;
            }
            if (step > res) {
                res = step;
            }
        }
        
        return res;
    }
};
