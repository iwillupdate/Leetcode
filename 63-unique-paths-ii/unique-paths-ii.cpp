class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        if(m < 0 || n < 0) return 0;
        if(obstacleGrid[m][n] == 1) return 0;
        if(m == 0 && n == 0) return 1;

        if(dp[m][n] != -1) return dp[m][n];

        int left = solve(m, n - 1, obstacleGrid, dp);
        int up = solve(m - 1, n, obstacleGrid, dp);

        return dp[m][n] = left + up;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        vector<vector<int>> dp(row, vector<int>(col, -1));
        return solve(row - 1, col - 1, obstacleGrid, dp);
    }
};
