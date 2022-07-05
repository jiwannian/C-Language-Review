#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include"game.h"

void Initboard1(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i=0;i<rows;i++)
	{
		for (j=0;j<cols;j++)
		{
			board[i][j] = set;
		}
	}
}

void Playboard(char board[ROWS][COLS], int row1, int col1)
{
	printf("\n");
	int i = 0;
	int j = 0;
	printf("+ ");
	for (i = 1;i <=col1;i++)
	{
		printf("%d ", i);
	}
	printf("--y轴");
	printf("\n");
	for (i = 1;i <= row1;i++)
	{
		printf("%d ", i);
		for (j = 1;j <= col1;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("|\n");
	printf("x轴\n");
	printf("\n");
}
void Setmine(char mine[ROWS][COLS], int row1, int col1)
{
	int count = 0;
	while (count < MINE_COUNT)
	{
		int x = rand() % row1 + 1;
		int y = rand() % col1 + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count++;
		}
	}
}

int judg_count(char mine[ROWS][COLS],int x,int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';

}
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row1, int col1)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win <= row1 * col1 - MINE_COUNT)
	{
		int n = 0;
		printf("请输入坐标>:");
		scanf("%d，%d", &x, &y);

		if (x <= row1&&x>=1&&y>=1&&y<=col1)
		{
			if (mine[x][y] == '1')
			{
				printf("恭喜你踩到雷了，game over!!!\n");
				Playboard(mine, ROW1, COL1);
				break;
			}
			else
			{
				n=judg_count(mine,x,y);
				show[x][y] = n + '0';
				system("cls");
				Playboard(show, ROW1, COL1);
				win++;
			}
		}
		else
		printf("坐标输入非法！！！请重新输入！！！\n");

	}
	if (win = row1 * col1 - MINE_COUNT)
	{
		printf("你赢了！！！\n");
	}
}