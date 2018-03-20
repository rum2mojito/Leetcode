// 413. Arithmetic Slices

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() == 0) {
            return 0;
        }
        int a=2 , b=2 , d=A[1]-A[0] , res=0;
        for (int i=2;i<A.size();i++) {
            if (A[i] - A[i-1] == d) {
                b++;
            }
            else {
                d = A[i] - A[i-1];
                b = 2;
                for (int j=1;j<=a-2;j++) {
                    res += j;
                }
                a = 2;
            }
            if (b>a) {
                a = b;
            }
        }
        for (int j=1;j<=a-2;j++) {
            res += j;
        }
        
        return res;
    }
};
