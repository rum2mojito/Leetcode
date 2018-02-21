// 784. Letter Case Permutation

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        if (S.length() == 0) {
            res.push_back("");
            return res;
        }
        bfs (S,res,0);
        return res;
    }
    
    void bfs (string s , vector<string> &res  , int i) {
        if (i+1 == s.length()) {
            if (s[i]>='A' && s[i]<='Z') {
                string str = s;
                str[i] = str[i] - 'A' + 'a';
                res.push_back(str);
            }
            res.push_back(s);
            if (s[i]>='a' && s[i]<='z') {
                string str = s;
                str[i] = str[i] - 'a' + 'A';
                res.push_back(str);
            }
        }
        else {
            if (s[i]>='A' && s[i]<='Z') {
                string str = s;
                str[i] = str[i] - 'A' + 'a';
                bfs (str , res , i+1);
            }
            bfs (s, res , i+1);
            if (s[i]>='a' && s[i]<='z') {
                string str = s;
                str[i] = str[i] - 'a' + 'A';
                bfs (str , res , i+1);
            }
        }
    }
};
