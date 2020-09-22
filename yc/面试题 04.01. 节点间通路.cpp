#include <vector>
#include <set>
#include <queue>
using namespace std;

class Solution {
private:
    vector<set<int>> g;
    bool *visited;

    bool dfs(int start, int target) {
        if (start == target)
            return true;
        visited[start] = true;

        bool ans = false;

        for (auto iter = g[start].begin(); iter != g[start].end(); ++iter) {
            if (!visited[*iter]) {
                ans = ans || dfs(*iter, target);
            }
        }

        return ans;
    }

    bool bfs(int start, int target) {
        if (start == target) 
            return true;
        
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited[node] = true;

            if (node == target)
                return true;
            
            for (auto iter = g[node].begin(); iter != g[node].end(); ++iter) {
                if (!visited[*iter]) {
                    q.push(*iter);
                }
            }
        }

        return false;
    }

public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        visited = new bool [n];
        for (int i = 0; i < n; ++i) {
            g.push_back(set<int>());
            visited[i] = false;
        }

        for (int i = 0; i < graph.size(); ++i) {
            if (graph[i][0] != graph[i][1]) {
                g[graph[i][0]].insert(graph[i][1]);
            }
        }

        // return dfs(start, target);
        return bfs(start, target);
    }
};