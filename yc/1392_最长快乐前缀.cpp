
// KMP
#include <string>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        int *next = new int [s.size() + 1];
        int i = 0;
        int j = -1;
        next[i] = j;

        while (i < s.size()) {
            if (j == -1 || s[i] == s[j]) {
                i++;
                j++;
                next[i] = j;
            }
            else {
                j = next[j];
            }
        }

        return s.substr(0, next[s.size()]);
    }
};