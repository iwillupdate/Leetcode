class Solution {
public:
    double helper(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        int s = 0; // min. #elements from nums1 i can add to the left partition
        int e = m; //max. #elements from nums1 i can add to the left partition

            while (s <= e) {

            int x = s + (e - s) / 2;

            // add first 'x' elements from nums1 i.e. nums1[0..x-1] to the
            // left partition and the remaining 'm-x' elements from nums1 i.e.
            // nums1[x...m-1] to the right partition

            int l1 = x == 0 ? INT_MIN : nums1[x - 1];
            int r1 = x == m ? INT_MAX : nums1[x];

            // since the size of both the left and right parititon is equal i.e. (n+m)/2
            // add the first y=(n+m)/2-x elements from nums2 i.e. nums2[0...y-1] to the
            // left partition and the remaining 'n-y' elements from nums2 i.e. nums2[y...n-1]
            // to the right partition.

            int y = (m + n) / 2 - x;

            int l2 = y == 0 ? INT_MIN : nums2[y - 1];
            int r2 = y == n ? INT_MAX : nums2[y];

            // can we add first 'x' elements from nums1 i.e. nums1[0...x-1]
            // to the left partition ?

            if (l1 <= r2 and l2 <= r1) {
                // i've found a valid partition
                if ((m + n) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return min(r1, r2);
                }
            } else {
                if (l1 > r2) {
                    // decrease l1 -> reduce the search space from [s, e] to [s, x-1]
                    e = x - 1;
                } else if (r1 < l2) {
                    // increase r1 -> increase l1 : reduce the search space from [s, e] to [x+1, e]
                    s = x + 1;
                }
            }

        }

        return 0.0;

    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        return nums1.size() <= nums2.size() ? helper(nums1, nums2) : helper(nums2, nums1) ;

    }
};