#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int i, n, m;
    cin >> n;

    int* length = new int [n];
    for (i = 0; i < n; ++i) {
        cin >> length[i];
    }

    cin >> m;

    if (sum) 

    set <int> s;
    int total = 0;
    for (i = 0; i < n; ++i) {
        if (total < m) {
            total += length[i];
            s.insert(length[i]);
        }
        else {
            int diff = m - total + *s.end();
            if (diff > length[i]) {
                total += length[i];
                s.insert(length[i]);
            }
            else {

            }
        }
    }

}