#include <vector>

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        int *dp = new int [n];
        int i, j;

        dp[0] = grid[0][0];
        for (i = 1; i < n; ++i)
            dp[i] = dp[i-1] + grid[i][0];

        for (j = 1; j < m; ++j)
        {
            dp[0] += grid[0][j];
            for (i = 1; i < n; ++i)
            {
                dp[i] = this->minNum(dp[i], dp[i-1]) + grid[i][j];
            }
        }

        return dp[n-1];
    }

    int minNum(int i, int j) {
        return i > j ? j : i;
    }
};