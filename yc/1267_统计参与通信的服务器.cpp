#include <vector>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> row(grid.size(), 0);
        vector<int> col(grid[0].size(), 0);
        vector<vector<int>> point;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    ++row[i];
                    ++col[j];
                    vector<int> tmp = {i, j};
                    point.push_back(tmp);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < point.size(); ++i) {
            if (row[point[i][0]] >= 2 || col[point[i][1]] >= 2) {
                ans++;
            }
        }

        return ans;
    }
};