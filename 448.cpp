// 448. Find All Numbers Disappeared in an Array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 0) {
            return res;
        }
        map<int,int> mp;
        map<int,int>::iterator iter;
        
        for (int i=0;i<nums.size();i++) {
            mp[nums[i]] = i;
        }
        
        for (int i=1;i<nums.size()+1;i++) {
            iter = mp.find(i);
            if (iter == mp.end()) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};
