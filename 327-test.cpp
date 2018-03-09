/*
327. Count of Range Sum
test file for Algo. homework.
2018/03/09
*/

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> sum(1,0) , sum2;
        for (int i = 0; i < nums.size(); i++) {
            sum.push_back(sum.back() + nums[i]);
        }
        sum2 = sum;
        cout << "n" <<'\t' << "m" << '\t' << "i" << endl;
        cout << merge_count(sum, 0, sum.size(), lower, upper) << endl;
        cout << "--------------------" << endl;
        return merge_count2(sum2, 0, sum2.size(), lower, upper);
    }
    
    int binary_search_for_m(vector<long>& sum, long sum_i, int LOWER, int low, int high) {
        /*
        Find the smallest m in [low, high - 1]
        such that sum[m] - sum_i >= LOWER
        using binary search. If not found,
        return high.
        */
        int m = (low+high)/2;
        cout << sum[m] << endl;
        if (low == high) {
            return high;
        }
        if (sum[m]-sum_i >= LOWER) {
            if (sum[m]-sum_i == LOWER) {
                return m;
            }
            return min (m , binary_search_for_m(sum, sum_i, LOWER, low, m));
        }
        else {
            return binary_search_for_m(sum, sum_i, LOWER, m+1, high);
        }
    }

    int binary_search_for_n(vector<long>& sum, long sum_i, int UPPER, int low, int high) {
        /*
        Find the smallest n in [low, high - 1]
        such that sum[n] - sum_i > UPPER
        using binary search. If not found,
        return high.
        */
        int n = (low+high)/2;
        cout << sum[n] << endl;
        if (low == high) {
            return high;
        }
        if (sum[n]-sum_i > UPPER) {
            return min (n , binary_search_for_n(sum, sum_i, UPPER, low, n));
        }
        else {
            return binary_search_for_n(sum, sum_i, UPPER, n+1, high);
        }
    }

    int merge_count(vector<long>& sum, int low, int high, int LOWER, int UPPER) {
        int mid = low + (high-low) / 2;
        if (high-low <= 1)
            return 0;
        int count = merge_count(sum, low, mid, LOWER, UPPER)+merge_count(sum, mid, high, LOWER, UPPER);
        int m_low = mid, m_high = high, n_low = mid, n_high = high;
        for (int i = low; i < mid; i++) {
            int m=mid, n=mid;
            while (m < high && sum[m] - sum[i] < LOWER) ++m;
            while (n < high && sum[n] - sum[i] <= UPPER) ++n;
            // int m = binary_search_for_m(sum, sum[i], LOWER, m_low, m_high);
            // int n = binary_search_for_n(sum, sum[i], UPPER, n_low, n_high);
            cout << "##############" << endl;
            for (int i=0;i<sum.size();i++) {
                cout << sum[i] << '\t';
            }
            cout << endl;
            cout << sum[n] << '\t' << sum[m] << '\t' << sum[i] << endl;
            count += n - m;
        }
        sort(sum.begin() + low, sum.begin() + high); // You may assume the time complexity here is O(nlog(n)).
        return count;
    }
    
    int merge_count2(vector<long>& sum, int low, int high, int LOWER, int UPPER) {
        int mid = low + (high-low) / 2;
        if (high-low <= 1)
            return 0;
        int count = merge_count(sum, low, mid, LOWER, UPPER)+merge_count(sum, mid, high, LOWER, UPPER);
        int m_low = mid, m_high = high, n_low = mid, n_high = high;
        for (int i = low; i < mid; i++) {
            int m = binary_search_for_m(sum, sum[i], LOWER, m_low, m_high);
            cout << "@@@" << endl;
            int n = binary_search_for_n(sum, sum[i], UPPER, n_low, n_high);
            cout << "##############" << endl;
            for (int i=0;i<sum.size();i++) {
                cout << sum[i] << '\t';
            }
            cout << endl;
            cout << sum[n] << '\t' << sum[m] << '\t' << sum[i] << endl;
            count += n - m;
        }
        sort(sum.begin() + low, sum.begin() + high); // You may assume the time complexity here is O(nlog(n)).
        return count;
    }
    //
    int countAndMergeSort(vector<long> &sums, int start, int end, int lower, int upper) {
        if (end - start <= 1) return 0;
        int mid = start + (end - start) / 2;
        int cnt = countAndMergeSort(sums, start, mid, lower, upper) + countAndMergeSort(sums, mid, end, lower, upper);
        int j = mid, k = mid, t = mid;
        vector<int> cache(end - start, 0);
        for (int i = start, r = 0; i < mid; ++i, ++r) {
            while (k < end && sums[k] - sums[i] < lower) ++k;
            while (j < end && sums[j] - sums[i] <= upper) ++j;
            while (t < end && sums[t] < sums[i]) cache[r++] = sums[t++];
            cout << "##############" << endl;
            for (int i=0;i<sums.size();i++) {
                cout << sums[i] << '\t';
            }
            cout << endl;
            cout << sums[j] << '\t' << sums[k] << '\t' << sums[i] << endl;
            cache[r] = sums[i];
            cnt += j - k;
        }
        copy(cache.begin(), cache.begin() + t - start, sums.begin() + start);
        return cnt;
    }
};
