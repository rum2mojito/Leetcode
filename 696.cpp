// 696. Count Binary Substrings

class Solution {
public:
    int countBinarySubstrings(string s) {
        if (s.length() == 0) {
            return 0;
        }
        int zero = 0 , one = 0 , res = 0;
        bool flag;
        if (s[0] == '0') {
            flag = false;
            zero++;
        }
        else {
            flag = true;
            one++;
        }
        
        for (int i=1;i<s.length();i++) {
            if (s[i] == '0') {
                if (flag) {
                    zero = 1;
                    flag = false;
                    if (zero<=one) {
                        res++;
                    }
                }
                else {
                    zero++;
                    if (zero<=one) {
                        res++;
                    }
                }
            }
            else {
                if (!flag) {
                    one = 1;
                    flag = true;
                    if (zero>=one) {
                        res++;
                    }
                }
                else {
                    one++;
                    if (zero>=one) {
                        res++;
                    }
                }
            }
        }
        
        return res;
    }
};
