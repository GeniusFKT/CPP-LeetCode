class Solution {
public:
    int C[131][131];
    int pow[27][131];
    int **dp;

    void calc() {
        for (int i = 0; i <= 130; ++i) {
            this->C[i][0] = 1;
            this->C[i][1] = i;
            this->C[i][i] = 1;
        }

        for (int i = 3; i <= 130; ++i) {
            for (int j = 2; j < i; ++j) {
                this->C[i][j] = (this->C[i-1][j-1] + this->C[i-1][j]) % 1000000007;
            }
        }

        for (int i = 1; i <= 26; ++i) {
            pow[i][0] = 1;
            pow[i][1] = i;
        }

        for (int i = 1; i <= 26; ++i) {
            for (int j = 2; j <= 130; ++j) {
                pow[i][j] = (pow[i][j-1] * long(i)) % 1000000007;
            }
        }
    }

    int keyboard(int k, int n) {
        this->calc();
        this->dp = new int *[27];
        for (int i = 1; i <= 26; ++i) {
            dp[i] = new int [n+1];
        }

        for (int j = 1; j <= n; ++j) {
            if (j <= k)
                dp[1][j] = 1;
            else
                dp[1][j] = 0;
        }

        for (int i = 2; i <= 26; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j <= k) {
                    dp[i][j] = this->pow[i][j];
                }
                else {
                    long tmp = 0;
                    for (int t = 0; t <= k; ++t) {
                        tmp += C[j][t] * long(dp[i-1][j-t]);
                        tmp %= 1000000007;
                    }
                    dp[i][j] = int(tmp);
                }
            }
        }

        return dp[26][n];
    }
};