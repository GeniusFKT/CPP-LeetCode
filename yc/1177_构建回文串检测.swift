class Solution {
    func canMakePaliQueries(_ s: String, _ queries: [[Int]]) -> [Bool] {
        var ans = [Bool]()
        
        let dictAll = self.preprocess(s: s)

        for i in 0 ..< queries.count {
            var counter = 0
            let firstDict = dictAll[queries[i][0]]
            var lastDict = dictAll[queries[i][1] + 1]
            
            for (key, value) in firstDict {
                lastDict[key]! -= value
            }
            
            for num in lastDict.values {
                if num % 2 != 0 {
                    counter += 1
                }
            }
            
            if counter / 2 <= queries[i][2] {
                ans.append(true)
            }
            else {
                ans.append(false)
            }
        }
        
        return ans
    }
    
    func preprocess(s: String) -> [Dictionary<Character, Int>] {
        var dictAll = [Dictionary<Character, Int>]()
        var dict = Dictionary<Character, Int>()
        
        dictAll.append(dict)
        
        for c in s {
            if let n = dict[c] {
                dict[c] = n + 1
            }
            else {
                dict[c] = 1
            }
            
            let tmp = dict
            dictAll.append(tmp)
        }
        
        return dictAll
    }
}