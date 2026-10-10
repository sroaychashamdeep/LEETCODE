
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        long long k = (long long)k1 + k2;
        vector<int> diff(nums1.size());

        long long total = 0;
        int mx = 0;

        for (int i = 0; i < nums1.size(); i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            mx = max(mx, diff[i]);
        }

        // If all differences can be eliminated
        if (total <= k)
            return 0;

        // Binary search for the smallest possible maximum difference
        int left = 0, right = mx;

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long needed = 0;

            for (int d : diff) {
                if (d > mid)
                    needed += d - mid;
            }

            if (needed <= k)
                right = mid;
            else
                left = mid + 1;
        }

        int limit = left;
        long long ans = 0;
        long long remaining = k;

        // Reduce every difference greater than limit
        for (int d : diff) {
            if (d > limit) {
                remaining -= d - limit;
                d = limit;
            }
            ans += 1LL * d * d;
        }

        // Use remaining operations to reduce limit-level differences
        // by one. Each such reduction saves 2*limit - 1.
        ans -= remaining * (2LL * limit - 1);

        return ans;
    }
};
