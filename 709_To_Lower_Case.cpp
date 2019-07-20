// Runtime: 4 ms, faster than 61.18% of C++ online submissions for To Lower Case.
// Memory Usage: 8.1 MB, less than 67.84% of C++ online submissions for To Lower Case.

class Solution {
public:
    string toLowerCase(string str) {
        for(int i=0; i< str.length(); i++) {
            if(str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = 'a' + (str[i] - 'A');
            }
        }
        return str;
    }
};
