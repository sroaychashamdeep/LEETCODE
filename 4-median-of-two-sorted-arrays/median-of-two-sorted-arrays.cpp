class Solution {
public:
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }
    int lenA = nums1.size();
    int lenB = nums2.size();
    int lowIdx = 0;
    int highIdx = lenA;
    while (lowIdx <= highIdx) {
        int partitionA = lowIdx + (highIdx - lowIdx) / 2;
        int partitionB = (lenA + lenB + 1) / 2 - partitionA;
        int maxLeftA = (partitionA == 0) ? INT_MIN : nums1[partitionA - 1];
        int minRightA = (partitionA == lenA) ? INT_MAX : nums1[partitionA];
        int maxLeftB = (partitionB == 0) ? INT_MIN : nums2[partitionB - 1];
        int minRightB = (partitionB == lenB) ? INT_MAX : nums2[partitionB];
        if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
            if ((lenA + lenB) % 2 == 0) {
                return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
            } else {
                return max(maxLeftA, maxLeftB);
            }
        } else if (maxLeftA > minRightB) {
            highIdx = partitionA - 1;
        } else {
            lowIdx = partitionA + 1;
        }
    }
    return 0.0;
}};