#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include"game.h"


void Initboard2(char board[ROW2][COL2], int row2, int col2)
{
	int x = 0;
	int y = 0;
	for (x = 0;x < ROW2;x++)
	{
		for (y = 0;y < COL2;y++)
		{
			board[x][y] = ' ';
		}
	}
}
void Playboard2(char board[ROW2][COL2], int row2, int col2)
{
	int i = 0;
	int j = 0;
	printf("\n");
	for (i = 0;i < row2;i++)
	{
		for (j = 0;j < col2;j++)
		{
			if (j < col2 - 1)
			{
				printf(" %c |", board[i][j]);
			}
			else
			{
				printf(" %c \n", board[i][j]);
			}
		}
		if (i < row2 - 1)
		{
			for (j = 0;j < col2;j++)
			{
				if (j < col2 - 1)
				{
					printf("---|");
				}
				else
				{
					printf("---\n");
				}
			}
		}
	}
	printf("\n");
}

void player_set(char board[ROW2][COL2], int row2, int col2)
{
	int x = 0;
	int y = 0;
	printf("玩家走！\n");
	printf("请输入坐标>:");
	while (1)
	{
		scanf("%d，%d", &x, &y);
		if (x > 0 && x <= ROW2 && y > 0 && y <= COL2)
		{
			board[x-1][y-1] = '*';
			break;
		}
		else
			printf("非法输入！！！\n");
	}
}

void containment()
{
	if
}
void conputer_set(char board[ROW2][COL2], int row2, int col2)
{
	int x = 0;
	int y = 0;
	int i = 0;
	printf("电脑走");
	for (i = 0;i < 6;i++)
	{
		printf("·");
		Sleep(100);
	}
	while (1)
	{
		containment();
		x = rand() % ROW2;
		y = rand() % COL2;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

int Is_full(char board[ROW2][COL2], int row2, int col2)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row2;i++)
	{
		for (j = 0;j < col2;j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
int juge(char board[ROW2][COL2], int row2, int col2)
{
	int i = 0;
	int j = 0;
	int full = 0;
		for (i = 0;i < row2;i++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j + 1] != ' ')
			{
				if (board[i][j + 1] == '*')
					return 1;
				else
					return 0;
			}
		}
		for (j = 0, i = 0;j < col2;j++)
		{
			if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j] && board[i + 1][j] != ' ')
			{
				if (board[i + 1][j] == '*')
					return 1;
				else
					return 0;
			}
		}
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		{
			if (board[1][1] == '*')
				return 1;
			else
				return 0;
		}
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		{
			if (board[1][1] == '*')
				return 1;
			else
				return 0;
		}
		full= Is_full(board, ROW2, COL2);
		if (full == 1)
		{
			return 2;
		}
		else
			return 3;
}
char judg_win(char board[ROW2][COL2], int row2, int col2)
{
	int win=juge(board, row2, col2);

	if (win == 1)
		return '*';
	else if (win == 0)
		return '#';
	else if(win==2)
		return 'Q';
	return 'C';
}