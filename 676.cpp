// 676. Implement Magic Dictionary

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (int i=0;i<dict.size();i++) {
            map<int,vector<string>>::iterator iter;
            iter = mp.find(dict[i].length());
            if (iter != mp.end()) {
                iter->second.push_back(dict[i]);
            }
            else {
                mp[dict[i].length()] = vector<string>(1,dict[i]);
            }
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        map<int,vector<string>>::iterator iter;
        iter = mp.find(word.length());
        if (iter != mp.end()) {
            for (int i=0;i<iter->second.size();i++) {
                int diff=0;
                for (int j=0;j<word.length();j++) {
                    if (iter->second[i][j] != word[j]) {
                        diff++;
                    }
                    if (diff > 1) {
                        break;
                    }
                }
                if (diff == 1) {
                    return true;
                }
            }
            return false;
        }
        else {
            return false;
        }
    }
private:
    map<int,vector<string>> mp;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
