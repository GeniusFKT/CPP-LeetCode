class Solution {
public:
    int paintingPlan(int n, int k) {
        int r, c;
        int ans = 0;
        for (r = 0; r <= n; ++r) {
            for (c = 0; c <= n; ++c) {
                if ((r + c) * n - r * c == k) {
                    if (r == n || c == n) {
                        return 1;
                    }
                    ans += this->C(n, r) * this->C(n, c);
                }
            }
        }

        return ans;
    }

    int C(int n, int r) {
        int result = 1;

        if (r == 0 || r == n)
            return result;

        for (int i = n; i >= n - r + 1; --i) {
            result *= i;
        }

        for (int i = 1; i <= r; ++i) {
            result /= i;
        }

        return result;
    }
};