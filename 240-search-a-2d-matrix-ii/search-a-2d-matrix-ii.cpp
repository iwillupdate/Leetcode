class Solution {
private:
    bool binarySearch(const vector<int>& mat, int target) {  // Pass by reference
        int n = mat.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mat[mid] == target) return true;
            else if (target > mat[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return false;  
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            // Check if target is within the range of the current row
            if (target >= matrix[i][0] && target <= matrix[i][m-1]) {
                if (binarySearch(matrix[i], target)) {
                    return true;
                }
            }
        }
        return false;
    }
};
