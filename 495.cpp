// 495. Teemo Attacking

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int result = 0, oldEnd = -1;
        for (int i = 0; i < timeSeries.size(); i++) {
            int newEnd = timeSeries[i] + duration - 1;
            if (newEnd > oldEnd) {
                result += min(duration, newEnd - oldEnd);
                oldEnd = newEnd;
            }
        }
        return result;
    }
};
