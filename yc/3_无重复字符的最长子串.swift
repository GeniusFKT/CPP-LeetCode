class Solution {
    func lengthOfLongestSubstring(_ s: String) -> Int {
        var set = Set<Character>()
        var head = s.startIndex
        var rear = s.startIndex
        var ans = 0
        
        while rear != s.endIndex {
            while rear != s.endIndex {
                if set.contains(s[rear]) {
                    break
                }
                else {
                    set.insert(s[rear])
                    rear = s.index(after: rear)
                }
            }
            
            ans = max(ans, s.distance(from: head, to: rear))

            set.remove(s[head])
            head = s.index(after: head)
        }
        
        return ans
    }
}
