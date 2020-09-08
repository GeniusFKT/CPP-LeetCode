class Solution {
    func largestNumber(_ cost: [Int], _ target: Int) -> String {
        var dp = [String]()
        
        // item 1, initial state
        for i in 0...target {
            let time = i / cost[0]
            if time == 0 || i % cost[0] != 0{
                dp.append("#")
            }
            else {
                dp.append(self.generateStr(c: "1", time: time))
            }
        }
        
        // item 2 to item 9
        for i in 1..<cost.count {
            for j in 0...target {
                if j >= cost[i] {
                    var chooseI = ""
                    if dp[j - cost[i]] != "#" {
                        chooseI = "\(i + 1)" + dp[j - cost[i]]
                    }
                    else {
                        if j == cost[i] {
                            chooseI = "\(i + 1)"
                        }
                        else {
                            continue
                        }
                    }
                    dp[j] = self.biggerStr(a: dp[j], b: chooseI)
                }
            }
        }
        
        if dp[target] != "#" {
            return dp[target]
        }
        
        return "0"
    }
    
    func generateStr(c: String, time: Int) -> String {
        var res = ""
        for _ in 0..<time {
            res += c
        }
        
        return res
    }
    
    func biggerStr(a: String, b: String) -> String {
        if a == "#" {
            return b
        }
        
        if b == "#" {
            return a
        }
        
        if a.count > b.count {
            return a
        }
        
        if a.count < b.count {
            return b
        }
        
        if a.count == b.count {
            if a > b {
                return a
            }
            else {
                return b
            }
        }
        
        return a
    }
}

let s = Solution()
s.largestNumber([4,3,2,5,6,7,2,5,5], 9)
