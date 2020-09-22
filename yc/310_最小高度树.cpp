#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
private:
    map<int, set<int>> graph;

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < n; ++i) {
            graph[i] = set<int>();
        }

        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].insert(edges[i][1]);
            graph[edges[i][1]].insert(edges[i][0]);
        }

        while (graph.size() > 2) {
            vector<int> deleteList;
            for (auto iter = graph.begin(); iter != graph.end(); ++iter) {
                if (iter->second.size() == 1) {
                    deleteList.push_back(iter->first);
                }
            }

            for (int i = 0; i < deleteList.size(); ++i) {
                int node = *(graph[deleteList[i]].begin());
                graph[node].erase(deleteList[i]);

                graph.erase(deleteList[i]);
            }
        }

        vector<int> ans;
        for (auto iter = graph.begin(); iter != graph.end(); ++iter) {
            ans.push_back(iter->first);
        }

        return ans;
    }
};