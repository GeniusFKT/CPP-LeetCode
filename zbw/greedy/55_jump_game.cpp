class Solution {
public:
    bool canJump(vector<int>& nums) {
        int idx=0;

        for (int i=idx+1; idx+nums[idx]<nums.size()-1 && i<=idx+nums[idx]; ++i)
        {
            if (idx + nums[idx] < i + nums[i])
                idx = i;
        }
        if (idx+nums[idx] >=nums.size()-1)
            return true;
        else
            return false;
    }
};