// 540. Single Element in a Sorted Array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size();
        int mid = (high)/2;
        
        while (mid != high) {
            if (nums[mid] == nums[mid+1]) {
                if (mid%2 != 0) high = mid-1;
                else low = mid+1;
            }
            else if (nums[mid-1] != nums[mid]) {
                return nums[mid];
            }
            else if (nums[mid+1] != nums[mid+2]) {
                return nums[mid+1];
            }
            else {
                if (mid%2 != 0) low = mid+1;
                else high = mid-1;
            }
            mid = (low+high)/2;
        }
        return nums[mid];
    }
};
