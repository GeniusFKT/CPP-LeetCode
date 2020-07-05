class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0;
        while (start<cost.size())
        {
            int remain=0, i;
            for (i=start;i<(start+cost.size()) && remain>=0;++i)
            {
                remain += (gas[i % cost.size()] - cost[i % cost.size()]);
            }
            if (remain >= 0)
                return start;
            else
                start = i;
        }
        return -1;
    }
};