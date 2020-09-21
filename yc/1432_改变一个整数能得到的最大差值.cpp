#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        vector <int> t;
        int ans = 0;
        int maxChange = -1, minChange = -1;
        int maxDiff, minDiff;

        while (num != 0) {
            t.push_back(num % 10);
            num /= 10;
        }

        for (int i = t.size() - 1; i >= 0; --i) {
            if (maxChange == -1) {
                if (t[i] != 9) {
                    maxChange = t[i];
                    maxDiff = 9 - maxChange;
                    ans += maxDiff * pow(10, i);
                }
            }
            else {
                if (t[i] == maxChange) {
                    ans += maxDiff * pow(10, i);
                }
            }

            if (minChange == -1) {
                if (i == t.size() - 1 && t[i] != 1 || i != t.size() - 1 && t[i] != 0 && t[i] != 1) {
                    minChange = t[i];
                    if (i == t.size() - 1) {
                        minDiff = minChange - 1;
                    }
                    else {
                        minDiff = minChange;
                    }
                    ans += minDiff * pow(10, i);
                }
            }
            else {
                if (t[i] == minChange) {
                    ans += minDiff * pow(10, i);
                }
            }
        }

        return ans;
    }
};