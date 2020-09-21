#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// 带权并查集！
// find函数用于找某一节点所在集合的根结点
// p内并不一定存放根结点！！！

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        // initialize
        for (int i = 0; i < equations.size(); ++i) {
            string a = equations[i][0], b = equations[i][1];
            p[a] = a;
            p[b] = b;
            d[a] = 1;
            d[b] = 1;
        }

        // build set
        for (int i = 0; i < equations.size(); ++i) {
            string a = equations[i][0], b = equations[i][1];
            string ra = this->find(a);

            p[ra] = b;
            d[ra] = values[i] / d[a];
        }

        // get ans
        vector <double> ans;
        for (int i = 0; i < queries.size(); ++i) {
            string a = queries[i][0], b = queries[i][1];
            if (d.find(a) == d.end() || d.find(b) == d.end()) {
                ans.push_back(-1.0);
                continue;
            }
            else if (this->find(a) != this->find(b)) {
                ans.push_back(-1.0);
                continue;
            }
            else {
                ans.push_back(d[a] / d[b]);
            }
        }

        return ans;
    }

private:
    unordered_map <string, string> p;
    unordered_map <string, double> d;

    string find(string s) {
        if (s != p[s]) {
            string t = this->find(p[s]);
            d[s] *= d[p[s]];
            p[s] = t;
        }

        return p[s];
    }
};