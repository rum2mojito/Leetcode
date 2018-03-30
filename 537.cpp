// 537. Complex Number Multiplication

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        vector<int> s1 = trans(a), s2=trans(b);
        string res;
        stringstream ss;
        ss << s1[0]*s2[0]-s1[1]*s2[1];
        ss >> res;
        res+='+';
        stringstream ss2;
        ss2 << s1[0]*s2[1]+s1[1]*s2[0];
        string com;
        ss2 >> com;
        res += com;
        res+= 'i';
        return res;
    }
    
    vector<int> trans (string s) {
        string s1, s2;
        vector<int> res;
        bool flag = true;
        for (int i=0;i<s.length();i++) {
            if ((s[i]!='+') && flag) {
                s1 += s[i];
            }
            else if (flag) {
                stringstream ss;
                int real=0;
                ss << s1;
                ss >> real;
                res.push_back(real);
                flag = false;
            }
            else {
                s2 += s[i];
            }
        }
        stringstream ss;
        int c=0;
        ss << s2;
        ss >> c;
        res.push_back(c);
        return res;
    }
};
