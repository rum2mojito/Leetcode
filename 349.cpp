// 349. Intersection of Two Arrays

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if (nums1.size() == 0 || nums2.size() == 0) {
            return res;
        }
        sort (nums1.begin(),nums1.end());
        for (int i=0;i<nums2.size();i++) {
            int k=search(nums1,nums2[i],0,nums1.size()-1);
            if (k >= 0)
                res.push_back(nums2[i]);
            while (k >= 0) {
                k = search(nums1,nums2[i],0,nums1.size()-1);
            }
        }
        sort (res.begin(),res.end());
        return res;
    }
    
    int search (vector<int> &num, int key, int l, int h) {
        int mid = (l+h)/2;
        if (l > h) {
            return -1;
        }
        if (num[mid] == key) {
            num.erase(num.begin()+mid);
            return mid;
        }
        if (key < num[mid]) {
            return search (num,key,l,mid-1);
        }
        else if (key > num[mid]) {
            return search (num,key,mid+1,h);
        }
    }
};
