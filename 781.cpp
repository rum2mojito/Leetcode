// 781. Rabbits in Forest

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res=0;
        map<int,int> mp;
        map<int,int>::iterator iter;
        for (int i=0;i<answers.size();i++) {
            if (answers[i] == 0) {
                res++;
                continue;
            }
            iter = mp.find(answers[i]);
            if (iter != mp.end()) {
                mp[answers[i]]++;
            }
            else {
                mp[answers[i]] = 1;
            }
        }
        iter = mp.begin();
        while (mp.end() != iter) {
            while (iter->second > 0) {
                iter->second -= (iter->first+1);
                res += iter->first+1;
            }
            iter++;
        }
        return res;
    }
};
