#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int *ctr = new int [N + 1];
        for (int i = 1; i <= N; ++i) {
            ctr[i] = 0;
        }

        for (int i = 0; i < trust.size(); ++i) {
            ctr[trust[i][0]]--;
            ctr[trust[i][1]]++;
        }

        for (int i = 1; i <= N; ++i) {
            if (ctr[i] == N - 1) {
                return i;
            }
        }

        return -1;
    }
};