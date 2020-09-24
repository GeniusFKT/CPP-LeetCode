#include <vector>
using namespace std;

class Solution {
private:
    int *inDegree;
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        inDegree = new int [n];
        for (int i = 0; i < n; ++i) {
            inDegree[i] = 0;
        }

        for (int i = 0; i < edges.size(); ++i) {
            inDegree[edges[i][1]]++;
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};