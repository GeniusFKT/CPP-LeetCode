class Solution {
    func divingBoard(_ shorter: Int, _ longer: Int, _ k: Int) -> [Int] {
        if k == 0 {
            return [Int]()
        }

        if shorter == longer {
            return [shorter * k]
        }

        var res = [Int]()

        for idx in 0 ... k {
            res.append(idx * shorter + (k - idx) * longer)
        }

        res.sort(){$0 < $1}

        return res
    }
}