class Solution {
    func reverseWords(_ s: String) -> String {
        if s.isEmpty {
            return s
        }
        
        var ans = ""
        let wordList = s.split(separator: " ")
        
        for word in wordList {
            ans += String(word).reversed()
            ans += " "
        }
        
        ans.removeLast()
        return ans
    }
}
