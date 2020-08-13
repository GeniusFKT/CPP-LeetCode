#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map <char, int> tmp1;
    map <char, int> tmp2;
    string str1;
    string str2;
    
    cin >> str1 >> str2;
    
    if (str1.size() != str2.size())
    {
        cout << "false";
        return 0;
    }
    
    int i;
    map<char, int>::iterator iter;
    for (i = 0; str1[i] != '\0'; ++i)
    {
        iter = tmp1.find(str1[i]);
        if (iter == tmp1.end())
            tmp1[str1[i]] = 1;
        else
            tmp1[str1[i]] ++;
        
        iter = tmp2.find(str2[i]);
        if (iter == tmp2.end())
            tmp2[str2[i]] = 1;
        else
            tmp2[str2[i]] ++;
    }
    
    map<char, int>::iterator iter2;
    for (iter = tmp1.begin(); iter != tmp1.end(); iter++)
    {
        iter2 = tmp2.find(iter->first);
        if (iter2 == tmp2.end())
        {
            cout << "false";
            return 0;
        }
        
        if (iter2->second != iter->second)
        {
            cout << "false";
            return 0;
        }
    }
    
    cout << "true";
    return 0;
}