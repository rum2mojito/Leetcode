// 258. Add Digits

class Solution {
public:
    int addDigits(int num) {
        return num % 9 == 0 ? (num == 0 ? 0 : 9) : num % 9;
    }
};
