// 647. Palindromic Substrings

class Solution {
public:
    int countSubstrings(string s) {
        int res = s.length();
        if (res == 0) {
            return 0;
        }
        
        for (int i=0;i<s.length()-1;i++) {
            res += recur(s,i);
        }
        
        return res;
    }
    
    int recur (string s, int k) {
        int res = 0;
        for (int i=1;i+k<s.length()&&k-i>=0;i++) {
            if (s[k-i] == s[k+i]) {
                res++;
            }
            else {
                break;
            }
        }
        
        if (s[k] == s[k+1]) {
            res++;
            for (int i=1;i+k+1<s.length()&&k-i>=0;i++) {
                if (s[k-i] == s[k+i+1]) {
                    res++;
                }
                else {
                    break;
                }
            }
        }
        
        return res;
    }
};
