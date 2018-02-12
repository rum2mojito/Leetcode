// 762. Prime Number of Set Bits in Binary Representation

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        for (int i=L;i<=R;i++) {
            if (IsPrime(binary(i))) {
                res++;
            }
        }
        return res;
    }
    
    int binary (int x) {
        vector<int> res;
        while (x!=0) {
            if (x%2 == 1)
                res.push_back(x%2);
            x /= 2;
        }
        return res.size();
    }
    
    bool IsPrime (int x) {
        if (x == 1) {
            return false;
        }
        for (int i=2;i<x;i++) {
            if (x%i == 0) {
                return false;
            }
        }
        return true;
    }
};
