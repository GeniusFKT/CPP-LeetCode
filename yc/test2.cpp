#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cn2(int n) {
    return n * (n - 1) / 2;
}

int main() {
    int T, n;
    cin >> T;

    while (cin >> n) {
        int ans = 0;
        if (n % 2 == 1) {
            for (int i = 1; i <= n; ++i){
                if (cn2(i) <= n - 1) {
                    ans = i;
                }
                else {
                    break;
                }
            }
        }
        else {
            ans = 1;
            for (int i = 0; i < n - 1; ++i) {
                ans *= 2;
            }
        }

        cout << ans << endl;
    }
}