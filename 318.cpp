// 318. Maximum Product of Word Lengths

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        vector<vector<int>> ele(words.size() , vector<int> (26,0));
        
        for (int i=0;i<words.size();i++) {
            for (int j=0;j<words[i].length();j++) {
                ele[i][words[i][j] - 'a']++;
            }
        }
        
        for (int i=0;i<words.size();i++) {
            for (int j=i+1;j<words.size();j++) {
                bool flag = true;
                for (int k=0;k<26;k++) {
                    if ((ele[i][k] != 0) && (ele[j][k] != 0)) {
                        flag = false;
                        break;
                    }
                }
                int h = words[i].length()*words[j].length();
                if (flag && h > res) {
                    res = h;
                }
            }
        }
        
        return res;
    }
};
