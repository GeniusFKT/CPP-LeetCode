class Solution {
    func tribonacci(_ n: Int) -> Int {
        var first = 0, second = 1, third = 1, fourth = 2

        if n == 0 {
            return first
        }

        if n == 1 {
            return second
        }

        if n == 2 {
            return third
        }

        if n == 3 {
            return fourth
        }

        for _ in 0 ..< n-3 {
            first = second
            second = third
            third = fourth
            fourth = first + second + third
        }

        return fourth
    }
}