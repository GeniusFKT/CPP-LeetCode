#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ans = "";

        if (nums.size() == 1) {
            ans = to_string(nums[0]);
        }
        else if (nums.size() == 2) {
            ans = to_string(nums[0]) + "/" + to_string(nums[1]);
        }
        else {
            ans = to_string(nums[0]) + "/(";
            for (int i = 1; i < nums.size() - 1; ++i) {
                ans += (to_string(nums[i]) + "/");
            }
            ans += to_string(nums[nums.size()-1]) + ")";
        }

        return ans;
    }
};