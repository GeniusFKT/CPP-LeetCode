#include <iostream>
#include <set>
using namespace std;

bool judge(int i) {
    set <int> tmp;
    int j = i;
    
    for (int k = 0; k < 6; ++k) {
        tmp.insert(j % 10);
        j /= 10;
    }

    if (tmp.size() < 6) {
        return false;
    }

    if ((i / 100000) == 0) {
        return false;
    }

    int a = i % 100;
    int b = (i / 100) % 100;
    int c = (i / 10000) % 100;

    if (b + c == a) {
        return true;
    }
    return false;
}

int main() {
    int M, N;
    cin >> M >> N;

    int ans = 0;
    for (int i = M; i <= N; ++i) {
        if (judge(i)) {
            ans++;
        }
    }

    cout << ans;
    return 0;
}