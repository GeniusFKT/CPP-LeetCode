#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int rev_ptr;
        int idx;

        for (rev_ptr = nums.size() - 1; rev_ptr > 0; --rev_ptr)
            if (nums[rev_ptr] > nums[rev_ptr - 1])
                break;

        if (rev_ptr > 0)
        {
            idx = this->findMinBiggerElement(nums, rev_ptr);
            this->swapElement(nums, rev_ptr - 1, idx);
            reverse(nums.begin() + rev_ptr, nums.end());
        }

        if (rev_ptr == 0)
            reverse(nums.begin(), nums.end());
    }

    int findMinBiggerElement(vector<int>& nums, int ptr) {
        int i;
        int res;
        bool flag = true;

        for (i = ptr; i < nums.size(); ++i)
            if (nums[i] > nums[ptr - 1])
                if (flag)
                    res = i;
                else
                    if (nums[i] < nums[res])
                        res = i;

        return res;
    }

    void swapElement(vector<int>& nums, int ptr1, int ptr2) {
        int tmp = nums[ptr1];
        nums[ptr1] = nums[ptr2];
        nums[ptr2] = tmp;
    }

};