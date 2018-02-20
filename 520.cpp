// 520. Detect Capital

class Solution {
public:
    bool detectCapitalUse(string word) {
        string str = word;
        
        for (int j=0;j<word.size();j++) {
            str[j] = toupper(str[j]);
        }
        if (str == word) {
            return true;
        }
        
        for (int i=1;i<word.length();i++) {
            if (word[i]>='A' && word[i]<='Z') {
                return false;
            }
        }
        return true;
    }
};
