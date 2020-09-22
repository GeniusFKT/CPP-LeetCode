#include <vector>
using namespace std;

class Solution {
private:
    bool **pre;

public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        pre = new bool *[n];
        for (int i = 0; i < n; ++i) {
            pre[i] = new bool [n];
            for (int j = 0; j < n; ++j) {
                pre[i][j] = false;
            }
        }

        for (int i = 0; i < prerequisites.size(); ++i) {
            pre[prerequisites[i][0]][prerequisites[i][1]] = true;
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (pre[i][k] && pre[k][j]) {
                        pre[i][j] = true;
                    }
                }
            }
        }

        vector<bool> ans;
        for (int i = 0; i < queries.size(); ++i) {
            ans.push_back(pre[queries[i][0]][queries[i][1]]);
        }

        return ans;
    }
};