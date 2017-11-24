#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define bool char
#define true 1
#define false 0


bool isValidSudoku(char **board, int boardRowSize, int boardColSize)
{
	char flag[10];
	int i, j, k;

	if (boardRowSize % 3 != 0)
	{
		return false;
	}
	else if (boardColSize % 3 != 0)
	{
		return false;
	}

	for (i = 0; i < boardRowSize; i++)
	{
		memset(flag, 0x1, sizeof(flag));
		for (j = 0; j < boardColSize; j++)
		{
			if (board[i][j] != '.')
			{
				if (flag[board[i][j] - '0'] == 0)
				{
					return false;
				}
				else
				{
					flag[board[i][j] - '0'] = 0;
				}
			}
		}
	}

	for (j = 0; j < boardColSize; j++)
	{
		memset(flag, 0x1, sizeof(flag));
		for (i = 0; i < boardRowSize; i++)
		{
			if (board[i][j] != '.')
			{
				if (flag[board[i][j] - '0'] == 0)
				{
					return false;
				}
				else
				{
					flag[board[i][j] - '0'] = 0;
				}
			}
		}
	}

	for (i = 0; i < boardRowSize; i += 3)
	{
		for (j = 0; j < boardColSize; j += 3)
		{
			memset(flag, 0x1, sizeof(flag));
			for (k = 0; k < 9; k++)
			{
				if (board[i + (k / 3)][j + (k % 3)] != '.')
				{
					if (flag[board[i + (k / 3)][j + (k % 3)] - '0'] == 0)
					{
						return false;
					}
					else
					{
						flag[board[i + k / 3][j + (k % 3)] - '0'] = 0;
					}
				}
			}
		}
	}

	return true;
}

int main()
{
	return 0;
}