class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> table;
        int len=0, start=0, max=0;
        for (int i=0;i<s.size();++i)
        { 
            if (table.find(s[i]) == table.end())
            {       
                len += 1;
                table[s[i]] = i;
            }
            else
            {   
                if (table[s[i]] < start)
                    len += 1;
                else
                {
                    start=table[s[i]]+1;
                    if (len > max)
                        max = len;
                    len = i-start+1;
                }
                table[s[i]] = i;
                
            }
        }
        if (len > max)
            max = len;
        return max;
    }
};