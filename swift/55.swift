// 55. Jump Game

class Solution {
    func canJump(_ nums: [Int]) -> Bool {
        if nums.count == 0 {
            return true
        }

        var max: Int = 0
        for i in 0..<nums.count {
            if i <= max {
                max = (i + nums[i]) > max ? (i + nums[i]) : max
            } else {
                break
            }
        }
        return max >= (nums.count - 1)
    }
}