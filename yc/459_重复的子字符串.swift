class Solution {
    func repeatedSubstringPattern(_ s: String) -> Bool {
        for i in 1 ..< s.count / 2 + 1 {
            if s.count % i != 0 {
                continue
            }
            
            var stridx = s.startIndex
            var nxtidx = s.index(stridx, offsetBy: i)
            let substr = s[stridx..<nxtidx]

            for j in 0 ..< s.count / i - 1 {
                stridx = nxtidx
                nxtidx = s.index(nxtidx, offsetBy: i)
                
                if substr != s[stridx..<nxtidx] {
                    break
                }
                
                if j == s.count / i - 2 {
                    return true
                }
            }
        }
        
        return false
    }
}


let a = Solution()

a.repeatedSubstringPattern("abcabcabc")
