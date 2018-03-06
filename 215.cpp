// 215. Kth Largest Element in an Array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        reverse(nums.begin(),nums.end());
        nums.push_back(-1);
        reverse(nums.begin(),nums.end());
        int res = nums[0];
        if (nums.size() == 1) {
            return res;
        }
        
        for (int i = nums.size()/2;i>0;i--) {
            make_heap (nums,i);
        }
        for (int j=0;j<k;j++) {
            res = nums[1];
            nums.erase(nums.begin()+1);
            for (int i = nums.size()/2;i>0;i--) {
                make_heap (nums,i);
            }
        }
        
        return res;
    }
    
    void make_heap (vector<int>& nums , int s) {
        int left = s*2;
        int right = s*2+1;
        int max;
        
        if (left < nums.size() && nums[left]>nums[s]) {
            max = left;
        }
        else {
            max = s;
        }
        
        if (right< nums.size() && nums[right]>nums[max]) {
            max = right;
        }
        if (max != s) {
            int tmp = nums[s];
            nums[s] = nums[max];
            nums[max] = tmp;
            make_heap (nums , max);
        }
    }
};
