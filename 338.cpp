// 338. Counting Bits

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        int k = log2(num);
        
        res.push_back(0);
        if (num == 0) {
            return res;
        }
        res.push_back(1);
        
        for (int i=0;i<=k;i++) {
            int m = res.size();
            for (int j = 0;j<m&&res.size()<=num;j++) {
                res.push_back(res[j]+1);
            }
            if (res.size() == num+1)
                break;
        }
        
        return res;
    }
};
