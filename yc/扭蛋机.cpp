#include <iostream>
#include <string>
using namespace std;

int main()
{
    string ans;
    int n;
    cin >> n;

    while (n != 0)
    {
        if (n % 2 == 0)
        {
            ans += "3";
            n = (n - 2) / 2;
        }
        else
        {
            ans += "2";
            n = (n - 1) / 2;
        }
    }

    for (int i = ans.size() - 1; i >= 0; --i)
        cout << ans[i];

    return 0;
}