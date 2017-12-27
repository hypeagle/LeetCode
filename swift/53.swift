
// 53. Maximum Subarray

class Solution {
    func maxSubArrayDC(_ nums: [Int], x: Int, y: Int) -> Int {
        var v: Int, L: Int, R: Int, maxs: Int
        if x + 1 == y {
            return nums[x]
        }
        
        let m = (x + y) >> 1
        maxs = max(maxSubArrayDC(nums, x: x, y: m), maxSubArrayDC(nums, x: m, y: y))
        
        v = 0
        L = nums[m - 1]
        for i in stride(from: m - 1, to: x - 1, by: -1) {
            v += nums[i]
            L = max(L, v)
        }
        
        v = 0
        R = nums[m]
        for i in m ..< y {
            v += nums[i]
            R = max(R, v)
        }
        
        return max(maxs, L + R)
    }
    
    func maxSubArray(_ nums: [Int]) -> Int {
//          var maxNums = nums
//          let numsLen = nums.count
//          
//          var maxValue: Int = maxNums[0]
//          
//          for i in 1 ..< numsLen {
//              maxNums[i] = max(nums[i], (maxNums[i - 1] + nums[i]))
//              if maxNums[i] > maxValue {
//                  maxValue = maxNums[i]
//              }
//          }
//          
//          return maxValue
        return maxSubArrayDC(nums, x: 0, y: nums.count)
    }
}

//  print(Solution().maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))
