#include <map>
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    int n;
    string str;

    while(cin >> n)
    {
        cin >> str;
        map<char, int> mymap;
        map<char, int>::iterator iter;

        map<int, char> ans;
        int ctr = 0;

        for (int i = 0; i < str.size(); ++i)
        {
            iter = mymap.find(str[i]);
            if (iter == mymap.end())
            {
                mymap[str[i]] = ctr;
                ctr++;
            }
            else
            {
                mymap[str[i]] = -1;
            }
        }

        for (iter = mymap.begin(); iter != mymap.end(); ++iter)
        {
            if (iter->second != -1)
                ans[iter->second] = iter->first;
        }

        if (ans.size() < n)
            cout << "Myon~" << endl;
        else
        {   
            auto iter2 = ans.begin();
            for (int _ = 1; _ < n; ++_)
                iter2++;

            cout << "[" << iter2->second << "]" << endl;
        }
    }
}