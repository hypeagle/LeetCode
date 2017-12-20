
// 52. N-Queens II

class Solution {
    let direction:[(Int, Int)] = [(0, -1), (0, 1), (-1, -1), (-1, 0), (-1, 1), (1, -1), (1, 0), (1, 1)]
    func setDot(board: inout [String], n: Int, ii: Int, jj: Int, index: Int) {
        var i = ii + direction[index].0
        var j = jj + direction[index].1
        while true {
            if i < 0 || i >= n || j < 0 || j >= n {
                break
            }
            board[i * n + j] = "."
            
            i += direction[index].0
            j += direction[index].1
        }
    }
    
    func totalNQueens(_ n: Int) -> Int {
        var retBoard: [[String]] = []
        
        let emptyBoard: [String] = Array.init(repeating: " ", count: n * n)
        var countIndex: [Int] = Array.init(repeating: 0, count: n)
        var board: [String] = []
        
        var index: Int = 0
        countIndex[index] = 0
        while index < n {
            if index == 0 {
                if countIndex[index] == n {
                    break
                }
                board = emptyBoard
            }
            var isOk = false
            for j in countIndex[index]..<n {
                if board[index * n + j] == " " {
                    board[index * n + j] = "Q"
                    for i in 0..<8 {
                        setDot(board: &board, n: n, ii: index, jj: j, index: i)
                    }
                    isOk = true
                    countIndex[index] = j
                    break
                }
            }
            if isOk {
                if index == (n - 1) {
                    var solution: [String] = []
                    var str: String = ""
                    for i in 0..<n {
                        str = ""
                        for j in 0..<n {
                            str += board[i * n + j]
                        }
                        solution.append(str)
                    }
                    retBoard.append(solution)
                    
                    if index == 0 {
                        break
                    }
                    
                    index -= 1
                    board = emptyBoard
                    for i in 0..<index {
                        board[i * n + countIndex[i]] = "Q"
                        for k in 0..<8 {
                            setDot(board: &board, n: n, ii: i, jj: countIndex[i], index: k)
                        }
                    }
                    countIndex[index] += 1
                } else {
                    index += 1
                    countIndex[index] = 0
                }
            } else {
                if index == 0 {
                    break
                } else {
                    index -= 1
                    board = emptyBoard
                    for i in 0..<index {
                        board[i * n + countIndex[i]] = "Q"
                        for k in 0..<8 {
                            setDot(board: &board, n: n, ii: i, jj: countIndex[i], index: k)
                        }
                    }
                    countIndex[index] += 1
                }
            }
        }
        
        return retBoard.count
    }
}

//  print(Solution().solveNQueens(5))
