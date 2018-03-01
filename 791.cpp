// 791. Custom Sort String

class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> k(26,0);
        string res;
        
        for (int i=0;i<T.length();i++) {
            int h = T[i]-'a';
            k[h]++;
        }
        
        for (int i=0;i<S.length();i++) {
            int h = S[i]-'a';
            res.insert (res.end(),k[h],S[i]);
            k[h] = 0;
        }
        
        for (int i=0;i<k.size();i++) {
            if (k[i] > 0) {
                res.insert(res.end(),k[i],i+'a');
            }
        }
        
        return res;
    }
};
