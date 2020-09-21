#include <string>
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    string makeLargestSpecial(string S) {
        if (S.size() <= 2) {
            return S;
        }

        multiset <string> myset;
        int oneCounter = 0, zeroCounter = 0, begin = 0;
        string ans = "";

        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '1') {
                oneCounter++;
            }
            else {
                zeroCounter++;
            }

            if (oneCounter == zeroCounter) {
                string tmp = this->makeLargestSpecial(S.substr(begin + 1, i - begin - 1));
                myset.insert("1" + tmp + "0");
                begin = i + 1;
            }
        }

        for (auto i = myset.rbegin(); i != myset.rend(); ++i) {
            ans += *i;
        }

        return ans;
    }
};