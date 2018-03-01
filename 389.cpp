// 389. Find the Difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = 0;
        
        for (int i=0;i<s.length();i++) {
            sum += t[i];
            sum -= s[i];
        }
        sum += t[s.length()];
        
        char res = sum;
        
        return res;
    }
};
