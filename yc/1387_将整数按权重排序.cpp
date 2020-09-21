#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
private:
    map<int, int> weight;

    void buildI(int i) {
        if (weight.find(i) != weight.end())
            return;
        else {
            if (i % 2 == 0) {
                buildI(i / 2);
                weight[i] = weight[i/2] + 1;
            }
            else {
                buildI(3 * i + 1);
                weight[i] = weight[3 * i + 1] + 1;
            }
        }
    }

public:
    int getKth(int lo, int hi, int k) {
        vector<int> v;
        weight[1] = 1;

        for (int i = lo; i <= hi; ++i) {
            v.push_back(i);
            buildI(i);
        }

        sort(v.begin(), v.end(), [&](int a, int b) {
            if (weight[a] != weight[b])
                return weight[a] < weight[b];
            else 
                return a < b;
        });
        return v[k-1];
    }
};