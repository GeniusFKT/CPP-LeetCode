#include <vector>
using namespace std;

class Solution {
private:
    int *parent;
    int find(int i) {
        if (parent[i] != i) {
            return find(parent[i]);
        }
        return i;
    }

public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int twoParentsNode = 0;
        int circleNode = 0;

        parent = new int [edges.size() + 1];
        for (int i = 1; i <= edges.size(); ++i) {
            parent[i] = i;
        }

        for (int i = 0; i < edges.size(); ++i) {
            if (parent[edges[i][1]] != edges[i][1]) {
                twoParentsNode = i;
            }
            else {
                if (find(edges[i][0]) == find(edges[i][1])) {
                    circleNode = i;
                }
                else {
                    parent[edges[i][1]] = edges[i][0];
                }
            }
        }

        if (twoParentsNode == 0) {
            return edges[circleNode];
        }
        else {
            if (circleNode == 0) {
                return edges[twoParentsNode];
            }
            else {
                vector<int> ans = {parent[edges[twoParentsNode][1]], edges[twoParentsNode][1]};
                return ans;
            }
        }

        return vector<int>();
    }
};