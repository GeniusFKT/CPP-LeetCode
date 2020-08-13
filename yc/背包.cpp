#include <iostream>
using namespace std;

int main()
{
    int N, V;
    cin >> N >> V;

    int *C = new int [N];
    int *W = new int [N];

    int i, j;
    for (i = 0; i < N; ++i)
        cin >> C[i] >> W[i];

    int **dp = new int *[N];
    for (i = 0; i < N; ++i)
    {
        dp[i] = new int [V+1];
        dp[i][0] = 0;
    }

    for (j = 0; j <= V; ++j)
    {
        if (j >= W[0])
            dp[0][j] = C[0];
        else
            dp[0][j] = 0;
    }

    for (j = 1; j < V; ++j)
    {
        for (i = 1; i < N; ++i)
        {
            if (j < W[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - W[i]] + C[i]);
        }
    }

    cout << dp[N-1][V-1];
}