#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        int *dp = new int [n];
        int i, j;
        bool flag = true;

        for (i = 0; i < n; ++i)
            if (flag && obstacleGrid[i][0] == 0)
                dp[i] = 1;
            else
            {
                flag = false;
                dp[i] = 0;
            }

        for (int j = 1; j < m; ++j)
        {
            if (obstacleGrid[0][j] == 1)
                dp[0] = 0;

            for (int i = 1; i < n; ++i)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i] = 0;
                    continue;
                }

                dp[i] += dp[i-1];
            }
        }
        return dp[n-1];
    }
};