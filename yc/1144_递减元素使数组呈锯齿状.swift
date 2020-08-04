class Solution {
    func movesToMakeZigzag(_ nums: [Int]) -> Int {
        var oddAns = 0
        var evenAns = 0
        var isEven = false

        for idx in 0 ..< nums.count {
            isEven = !isEven
            if isEven {
                if idx == 0 {
                    evenAns += nums[0] >= nums[1] ? nums[0] - nums[1] + 1 : 0 
                    continue
                }

                if idx == nums.count - 1 {
                    evenAns += nums[idx] >= nums[idx-1] ? nums[idx] - nums[idx-1] + 1 : 0
                    continue
                }

                let minAdj = min(nums[idx-1], nums[idx+1])
                evenAns += nums[idx] >= minAdj ? nums[idx] - minAdj + 1 : 0
            }
            else {
                if idx == nums.count - 1 {
                    oddAns += nums[idx] >= nums[idx-1] ? nums[idx] - nums[idx-1] + 1 : 0
                    continue
                }

                let minAdj = min(nums[idx-1], nums[idx+1])
                oddAns += nums[idx] >= minAdj ? nums[idx] - minAdj + 1 : 0
            }
        }

        return min(oddAns, evenAns)
    }
}