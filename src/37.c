#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 37. Sudoku Solver

// char flag[100][100][10];
// int addFlag(int i, int j, int *val) {
//     int k;
//     int retValue = 0;

//     *val = 0;
//     for(k = 1; k <= 9; k++) {
//         retValue += flag[i][j][k];
//         if(flag[i][j][k] == 1) {
//             *val = k;
//         }
//     }
//     return retValue;
// }

// void setFlag(int i, int j, int boardRowSize, int boardColSize, int value) {
//     int k;
//     int startI = (i / 3) * 3;
//     int startJ = (j / 3) * 3;

//     for(k = 0; k < boardRowSize; k++) {
//         flag[k][j][value] = 0;
//     }

//     for(k = 0; k < boardColSize; k++) {
//         flag[i][k][value] = 0;
//     }

//     for(k = 0; k < 9; k++) {
//         flag[startI + (k / 3)][startJ + (k % 3)][value] = 0;
//     }
// }

// void solveSudoku(char** board, int boardRowSize, int boardColSize) {
//     int i, j, k;
//     int val, count;

//     memset(flag, 0x1, sizeof(flag));

//     while(1) {        
//         count = 0;
//         for(i = 0; i < boardRowSize; i++) {
//             for(j = 0; j < boardColSize; j++) {
//                 if(board[i][j] != '.') {
//                     setFlag(i, j, boardRowSize, boardColSize, board[i][j] - '0');
//                     count++;
//                 } else if(addFlag(i, j, &val) == 1) {
//                     board[i][j] = val + '0';
//                     setFlag(i, j, boardRowSize, boardColSize, board[i][j] - '0');
//                     count++;
//                 }
//             }
//         }

//         if(count == (boardRowSize * boardColSize)) {
//             break;
//         }
//     }    
// }

#define bool char
#define true 1
#define false 0

bool check(char** board, int boardRowSize, int boardColSize, int i, int j, char val) {
    int k;
    int startI = (i / 3) * 3;
    int startJ = (j / 3) * 3;

    for(k = 0; k < boardRowSize; k++) {
        if(board[k][j] == val) {
            return false;
        }
    }

    for(k = 0; k < boardColSize; k++) {
        if(board[i][k] == val) {
            return false;
        }
    }

    for(k = 0; k < 9; k++) {
        if(board[startI + (k / 3)][startJ + (k % 3)] == val) {
            return false;
        }
    }

    return true;
}

bool backTrack(char **board, int boardRowSize, int boardColSize, int i, int j) {
    char c;

    if(i == boardRowSize) return true;
    if(j == boardColSize) return backTrack(board, boardRowSize, boardColSize, i + 1, 0);
    if(board[i][j] != '.') return backTrack(board, boardRowSize, boardColSize, i, j  +1);

    for(c = '1'; c <= '9'; c++) {
        if(check(board, boardRowSize, boardColSize, i, j, c)) {
            board[i][j] = c;
            if(backTrack(board, boardRowSize, boardColSize, i, j + 1)) return true;
            board[i][j] = '.';   
        }
    }

    return false;
}

void solveSudoku(char** board, int boardRowSize, int boardColSize) {
    backTrack(board, boardRowSize, boardColSize, 0, 0);
}

int main()
{
    int i, j;
    // char board[9][9] = {{'.','.','9','7','4','8','.','.','.'},{'7','.','.','.','.','.','.','.','.'},{'.','2','.','1','.','9','.','.','.'},{'.','.','7','.','.','.','2','4','.'},{'.','6','4','.','1','.','5','9','.'},{'.','9','8','.','.','.','3','.','.'},{'.','.','.','8','.','3','.','2','.'},{'.','.','.','.','.','.','.','.','6'},{'.','.','.','2','7','5','9','.','.'}};
    char board[9][9] = {{'.','.','.','2','.','.','.','6','3'},{'3','.','.','.','.','5','4','.','1'},{'.','.','1','.','.','3','9','8','.'},{'.','.','.','.','.','.','.','9','.'},{'.','.','.','5','3','8','.','.','.'},{'.','3','.','.','.','.','.','.','.'},{'.','2','6','3','.','.','5','.','.'},{'5','.','3','7','.','.','.','.','8'},{'4','7','.','.','.','1','.','.','.'}};
    char **boardExt = (char **)malloc(9 * sizeof(char *));
    for(i = 0; i < 9; i++) {
        boardExt[i] = (char *)board[i];
    }
    solveSudoku((char**)boardExt, 9, 9);
    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            printf("%c\t", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}