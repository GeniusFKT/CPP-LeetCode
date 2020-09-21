#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string S, T;
    cin >> S >> T;

    int ans = 0;
    int ptrS = 0, ptrT = 0;

    while (ptrT < m) {
        if (ptrS == n) {
            cout << "No";
            return 0;
        }

        if (S[ptrS] == T[ptrT]) {
            ans += (ptrS + 1);
            ptrT++;
        }

        ptrS++;
    }

    cout << "Yes" << endl;
    cout << ans;
    return 0;
}