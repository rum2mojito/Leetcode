// 453. Minimum Moves to Equal Array Elements

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0, moves = 0;
        auto minIt = min_element(nums.begin(), nums.end());
        for (auto i : nums) sum += i;
        return sum - *minIt * nums.size();
    }
};
