class Solution {
    func findMinFibonacciNumbers(_ k: Int) -> Int {
        var fab = [Int]()
        var first = 1, second = 1, third = 2
        var ans = 0
        var num = k
        var idx: Int
        fab.append(contentsOf: [1,1,2])

        while third <= num {
            first = second
            second = third
            third = first + second
            fab.append(third)
        }

        while num != 0 {
            idx = 0
            while true {
                idx += 1
                if fab[idx] <= num && fab[idx+1] > num {
                    break
                }
            }

            num -= fab[idx]
            ans += 1
        }

        return ans
    }
}