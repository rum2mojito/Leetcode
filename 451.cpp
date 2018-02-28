// 451. Sort Characters By Frequency

class Solution {
public:
    string frequencySort(string s) {
        if (s.length() == 0) {
            return "";
        }
        map<char,int> mp;
        map<char,int>::iterator iter;
        vector<pair<int,char>> pr;
        string res;
        
        for (int i=0;i<s.length();i++) {
            iter = mp.find(s[i]);
            if (iter != mp.end()) {
                iter->second++;
            }
            else {
                mp[s[i]] = 1;
            }
        }
        
        for (map<char,int>::const_iterator it = mp.begin(); it != mp.end(); it++) {
            pair<int,char> p(it->second, it->first);
            pr.push_back(p);
        }
        
        for (int i=0;i<pr.size();i++) {
            for (int j=i;j<pr.size();j++) {
                if (pr[i].first < pr[j].first) {
                    pair<int,char> p = pr[i];
                    pr[i] = pr[j];
                    pr[j] = p;
                }
            }
        }
        
        for (int i=0;i<pr.size();i++) {
            for (int j=0;j<pr[i].first;j++) {
                res += pr[i].second;
            }
        }
        
        return res;
    }
};
