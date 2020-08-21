class Solution {
    func palindromePairs(_ words: [String]) -> [[Int]] {
        var res = [[Int]]()
        
        for i in 0 ..< words.count {
            for j in 0 ..< words.count {
                if i == j {
                    continue
                }
                
                let word = words[i] + words[j]
                if self.isPalindrome(word: word) {
                    res.append([i, j])
                }
            }
        }
        
        return res
    }
    
    func isPalindrome(word: String) -> Bool {
        var idx1 = word.startIndex
        var idx2 = word.index(before: word.endIndex)
        
        for _ in 0 ..< word.count / 2 {
            if word[idx1] != word[idx2] {
                return false
            }
            idx1 = word.index(after: idx1)
            idx2 = word.index(before: idx2)
        }
        
        return true
    }
}
