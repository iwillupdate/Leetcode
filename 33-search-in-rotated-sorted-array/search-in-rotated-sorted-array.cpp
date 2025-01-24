class Solution {
public:
    int search(vector<int>& nums, int target) {
        //brute force - linear search
        // int n = nums.size();
        // for(int i=0 ; i<n ; i++){
        //     if (nums[i]==target){
        //         return i;
        //     }
        // }
        // return -1;

    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if mid is the target
        if (nums[mid] == target) {
            return mid;
        }

        // If left part is sorted
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;  // Target is in the left part
            } else {
                low = mid + 1;   // Eliminate the left part
            }
        }
        // If right part is sorted
        else {
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;  // Target is in the right part
            } else {
                high = mid - 1; // Eliminate the right part
            }
        }
    }

    return -1; // Target not found
}
};