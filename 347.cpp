// 347. Top K Frequent Elements

class Solution {  
public:  
    vector<int> topKFrequent(vector<int>& nums, int k) {  
        unordered_map<int, int> hash;  
        priority_queue<pair<int,int>> heap;  
        vector<int> ret;  
          
        for(int num:nums)   
            hash[num]++;  
          
        for(auto it:hash)   
            heap.push(make_pair(it.second, it.first));  
          
        for(int i=0; i<k; ++i) {  
            ret.push_back(heap.top().second);  
            heap.pop();  
        }  
          
        return ret;  
    }  
};  
