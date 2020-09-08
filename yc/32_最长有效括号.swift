class Solution {
    func longestValidParentheses(_ s: String) -> Int {
        var dp = [Int]()
        var idx = s.startIndex
        
        if s == "" {
            return 0
        }
        
        for _ in 0..<s.count {
            dp.append(0)
        }
        
        for i in 1..<s.count {
            idx = s.index(after: idx)
            if s[idx] == "(" {
                continue
            }
            else {
                if s[s.index(before: idx)] == "(" {
                    if i == 1 {
                        dp[i] = 2
                    }
                    else {
                        dp[i] = dp[i-2] + 2
                    }
                }
                else {
                    var res = dp[i-1]
                    if dp[i-1] == i {
                        continue
                    }
                    else {
                        let idx2 = s.index(idx, offsetBy: -dp[i-1] - 1)
                        if s[idx2] == ")" {
                            continue
                        }
                        else {
                            res += 2
                            
                            if idx2 != s.startIndex {
                                let dis = Int(s.distance(from: s.startIndex, to: idx2))
                                res += dp[dis-1]
                            }
                        }
                    }
                    dp[i] = res
                }
            }
        }
        
        print(dp)
        return dp.max()!
    }
}

let s = Solution()
s.longestValidParentheses("()")
