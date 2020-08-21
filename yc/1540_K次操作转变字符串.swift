class Solution {
    func canConvertString(_ s: String, _ t: String, _ k: Int) -> Bool {
        
        if s.count != t.count {
            return false
        }
        
        var diff = [Int]()
        
        var sIdx = s.startIndex
        var tIdx = t.startIndex
        
        while sIdx != s.endIndex {
            diff.append(Int(t[sIdx].asciiValue! + 26 - s[tIdx].asciiValue!) % 26)
            sIdx = s.index(after: sIdx)
            tIdx = t.index(after: tIdx)
        }
                
        var expectedTimes = [Int]()
        let times = k / 26
        let remainder = k % 26
        
        for i in 0 ..< 25 {
            if i < remainder {
                expectedTimes.append(times + 1)
            }
            else {
                expectedTimes.append(times)
            }
        }
        
        for i in diff {
            if i == 0 {
                continue
            }
            
            if expectedTimes[i - 1] == 0 {
                return false
            }
            
            else {
                expectedTimes[i - 1] -= 1
            }
        }
        
        return true
    }
}

let s = Solution()
s.canConvertString("input", "ouput", 9)
