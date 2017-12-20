
// 1. Two Sum

class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var retInts: [Int] = [0, 0]
        let numsLen = nums.count

outLoop: for i in 0..<numsLen {
            for j in i..<numsLen {
                if i != j && (nums[i] + nums[j]) == target {
                    retInts[0] = i;
                    retInts[1] = j;

                    break outLoop;
                }
            }
        }

        return retInts
    }
}