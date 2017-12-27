
// 54. Spiral Matrix

class Solution {
    func spiralOrder(_ matrix: [[Int]]) -> [Int] {
        let m = matrix.count
        if m == 0 {
            return []
        }
        let n = matrix[0].count
        if n == 0 {
            return []
        }
        var ret: [Int] = Array.init(repeating: 0, count: m * n)
        var flag: [Bool] = Array.init(repeating: false, count: m * n)
        var count = 0
        var x = 0
        var y = 0
        ret[count] = matrix[x][y]
        flag[0] = true
        count += 1
        
        while count < m * n {
            while count < m * n && y + 1 < n && !flag[x * n + y + 1] {
                ret[count] = matrix[x][y + 1]
                flag[x * n + y + 1] = true
                y += 1
                count += 1
            }
            
            while count < m * n && x + 1 < m && !flag[(x + 1) * n + y] {
                ret[count] = matrix[x + 1][y]
                flag[(x + 1) * n + y] = true
                x += 1
                count += 1
            }
            
            while count < m * n && y - 1 >= 0 && !flag[x * n + y - 1] {
                ret[count] = matrix[x][y - 1]
                flag[x * n + y - 1] = true
                y -= 1
                count += 1
            }
            
            while count < m * n && x - 1 >= 0 && !flag[(x - 1) * n + y] {
                ret[count] = matrix[x - 1][y]
                flag[(x - 1) * n + y] = true
                x -= 1
                count += 1
            }
        }
        
        return ret
    }
}

//  let matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
//  let matrix = [[3], [2]]
//  let ret = Solution().spiralOrder(matrix) 
//  
//  print(ret)
