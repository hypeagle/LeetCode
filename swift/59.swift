// 59. Spiral Matrix II

class Solution {
    func generateMatrix(_ n: Int) -> [[Int]] {
        var flag: [[Int]] = Array(repeating: Array(repeating: 0, count: n + 1), count: n + 1)
        var matrix: [[Int]] = Array(repeating: Array(repeating: 0, count: n), count: n)
        
        for i in 0...n {
            flag[n][i] = 1
            flag[i][n] = 1
        }
        
        var col = 0
        var row = 0
        var count = 1
        repeat {
            loopOne: for i in col...n {
                if(flag[row][i] == 1) {
                    row += 1
                    col = i - 1
                    break loopOne
                }
                flag[row][i] = 1
                matrix[row][i] = count
                count += 1
            }
            //            print("1:", matrix)
            loopTwo: for i in row...n {
                if(flag[i][col] == 1) {
                    row = i - 1
                    col -= 1
                    break loopTwo
                }
                flag[i][col] = 1
                matrix[i][col] = count
                count += 1
            }
            //            print("2:", matrix)
            loopThree: for i in stride(from: col, through: -1, by: -1) {
                if(i == -1 || flag[row][i] == 1) {
                    row -= 1
                    col = i + 1
                    break loopThree
                }
                flag[row][i] = 1
                matrix[row][i] = count
                count += 1
            }
            //            print("3:", matrix)
            loopFour: for i in stride(from: row, through: -1, by: -1) {
                if(i == -1 || flag[i][col] == 1) {
                    row = i + 1
                    col += 1
                    break loopFour
                }
                flag[i][col] = 1
                matrix[i][col] = count
                count += 1
            }
            //            print("4:", matrix)
        } while count <= n * n
        
        return matrix
    }
}

//let ret = Solution().generateMatrix(3)
//
//print(ret)