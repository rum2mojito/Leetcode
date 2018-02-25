// 442. Find All Duplicates in an Array

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,string> mp;
        map<int,string>::iterator iter;
        vector<int> res;
        
        for (int i=0;i<nums.size();i++) {
            iter = mp.find(nums[i]);
            if (iter != mp.end()) {
                res.push_back(nums[i]);
            }
            else {
                mp[nums[i]] = "ok";
            }
        }
        
        return res;
    }
};
