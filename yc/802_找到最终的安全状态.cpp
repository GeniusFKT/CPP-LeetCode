#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector <int> ans;
        bool *isTraverse = new bool [graph.size()];

        for (int i = 0; i < graph.size(); ++i)
            isTraverse[i] = false;

        while (true) {
            set <int> tmp;
            for (int i = 0; i < graph.size(); ++i) {
                if (!isTraverse[i]) {
                    if (graph[i].size() == 0) {
                        isTraverse[i] = true;
                        ans.push_back(i);
                        tmp.insert(i);
                    }
                }
            }

            bool status = false;

            for (int i = 0; i < graph.size(); ++i) {
                if (!isTraverse[i]) {
                    for (auto j = graph[i].begin(); j != graph[i].end(); ++j) {
                        if (tmp.find(*j) != tmp.end()) {
                            j = graph[i].erase(j);
                            j--;
                            status = true;
                        }
                    }
                }
            }

            if (!status) {
                break;
            }

            tmp.clear();
        }

        sort(ans.begin(), ans.end());
        return ans;
        
    }
};