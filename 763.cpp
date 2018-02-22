// 763. Partition Labels

class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char,int> mp;
        map<char,int>::iterator iter;
        vector<int> res;
        int p = 0;
        
        if (S == "") {
            res.push_back(0);
            return res;
        }
        
        for (int i=0;i<S.length();i++) {
            iter = mp.find(S[i]);
            if (iter->first != S[i]) {
                mp[S[i]] = i;
            }
            else {
                if (iter->second < i) {
                    iter->second = i;
                }
            }
        }
        
        while (p<S.length()) {
            iter = mp.find(S[p]);
            int r = check(S,p,iter->second,mp);
            res.push_back(r-p+1);
            p = r+1;
        }
        
        return res;
    }
    
    int check (string S , int st , int end , map<char,int> mp) {
        map<char,int>::iterator iter;
        for (int i=st;i<end;i++) {
            iter = mp.find(S[i]);
            if (iter->second > end) {
                return check (S,i,iter->second,mp);
            }
        }
        
        return end;
    }
};
