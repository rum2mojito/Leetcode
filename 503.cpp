// 503. Next Greater Element II

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res;
        for (int i=0;i<nums.size();i++) {
            res.push_back(search(nums,i));
        }
        return res;
    }
    
    int search (vector<int> &nums, int key) {
        for (int i=key+1;i<nums.size();i++) {
            if (nums[i] > nums[key]) {
                return nums[i];
            }
        }
        for (int i=0;i<key;i++) {
            if (nums[i] > nums[key]) {
                return nums[i];
            }
        }
        return -1;
    }
};
