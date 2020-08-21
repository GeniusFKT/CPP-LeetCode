class Solution {
    func lengthOfLastWord(_ s: String) -> Int {
        let tmp = s.split(separator: " ")
        if tmp.count == 0 {
            return 0
        }
        else {
            return tmp[tmp.count - 1].count
        }
    }
}
