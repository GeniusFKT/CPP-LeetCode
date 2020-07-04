class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> htable;

        for (int i = 0; i < strs.size(); ++i)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (htable.find(s) == htable.end())
                // htable[s] = vector<string>();
                htable.insert({{s, vector<string>()}});
            htable[s].push_back(strs[i]);
        }
        unordered_map<string, vector<string>>::iterator it;
        for (it = htable.begin(); it != htable.end(); ++it)
        {
            result.push_back(it->second);
        }
        return result;
    }
};