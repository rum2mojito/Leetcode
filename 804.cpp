// 804. Unique Morse Code Words

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",\
            ".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        map<string,int> mp;
        map<string,int>::iterator iter;
        int res=0;
        
        for (int i=0;i<words.size();i++) {
            string tmp;
            for (int j=0;j<words[i].length();j++) {
                tmp += morse[words[i][j]-'a'];
            }
            iter = mp.find(tmp);
            if (iter == mp.end()) {
                mp[tmp] = i;
                res++;
            }
        }
        return res;
    }
};
