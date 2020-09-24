#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int ctr = 0;
        set<int> leftSet;
        set<int> rightSet;
        bool *isVisited = new bool [graph.size()];

        for (int i = 0; i < graph.size(); ++i) {
            isVisited[i] = false;
        }

        while (ctr < graph.size()) {
            vector<int> leftContainer;
            vector<int> rightContainer;

            leftSet.clear();
            rightSet.clear();

            // find a start point
            for (int i = 0; i < graph.size(); ++i) {
                if (!isVisited[i]) {
                    leftSet.insert(i);
                    leftContainer.push_back(i);
                    isVisited[i] = true;
                    ctr++;
                    break;
                }
            }

            while (leftContainer.size() > 0) {
                for (int i = 0; i < leftContainer.size(); ++i) {
                    for (int j = 0; j < graph[leftContainer[i]].size(); ++j) {
                        if (isVisited[graph[leftContainer[i]][j]]) {
                            if (leftSet.find(graph[leftContainer[i]][j]) != leftSet.end()) {
                                return false;
                            }
                        }
                        else {
                            rightSet.insert(graph[leftContainer[i]][j]);
                            rightContainer.push_back(graph[leftContainer[i]][j]);
                            isVisited[graph[leftContainer[i]][j]] = true;
                            ctr++;
                        }
                    }
                }
                leftContainer.clear();

                for (int i = 0; i < rightContainer.size(); ++i) {
                    for (int j = 0; j < graph[rightContainer[i]].size(); ++j) {
                        if (isVisited[graph[rightContainer[i]][j]]) {
                            if (rightSet.find(graph[rightContainer[i]][j]) != rightSet.end()) {
                                return false;
                            }
                        }
                        else {
                            leftSet.insert(graph[rightContainer[i]][j]);
                            leftContainer.push_back(graph[rightContainer[i]][j]);
                            isVisited[graph[rightContainer[i]][j]] = true;
                            ctr++;
                        }
                    }
                }
                rightContainer.clear();
            }
        }
        
        return true;
    }
};