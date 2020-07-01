class Solution {
public:
    int uniquePaths(int m, int n) {
        int *dp = new int [n];
        int i;

        for (i = 0; i < n; ++i)
            dp[i] = 1;

        for (int _ = 1; _ < m; ++_)
            for (int i = 1; i < n; ++i)
                dp[i] += dp[i-1];

        return dp[n-1];
    }
};