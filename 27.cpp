// 27. Remove Element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> res;
        for (int i=0;i<nums.size();i++) {
            if (nums[i]!=val) {
                res.push_back(nums[i]);
            }
        }
            nums = res;
            return res.size();
    }
};
