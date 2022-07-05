#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include"game.h"

void game1()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	Initboard1(mine, ROWS, COLS, '0');
	Initboard1(show, ROWS, COLS, '*');
	Playboard(show, ROW1, COL1);
	Setmine(mine,ROW1,COL1);
	Findmine(mine,show,ROW1,COL1);
	
}
void menu1()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		system("cls");
		printf("扫雷~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("==================================\n");
		printf("       1.play        0.exit       \n");
		printf("==================================\n");
		printf("请选择>:");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game1();
			break;
		case 0:
			printf("退出游戏\n");
		default:
			printf("错误输入！！！\n");
			break;
		}

	} while (input);
}

void game2()
{
	char board[ROW2][COL2] = {0};
	Initboard2(board, ROW2, COL2);
	Playboard2(board,ROW2,COL2);
	while (1)
	{
		player_set(board, ROW2, COL2);
		system("cls");
		Playboard2(board, ROW2, COL2);
		if (judg_win(board, ROW2, COL2) != 'C')
		{
			break;
		}
		conputer_set(board, ROW2, COL2);
		system("cls");
		Playboard2(board, ROW2, COL2);
		if (judg_win(board, ROW2, COL2) != 'C')
		{
			break;
		}
	}
	if (judg_win(board, ROW2, COL2) == '*')
	{
		printf("恭喜你，你赢了！！！\n");
		system("pause");
	}
	else if (judg_win(board, ROW2, COL2) == '#')
	{
		printf("你个垃圾，这都输了!!!\n");
		system("pause");
	}
	else
	{
		printf("平局！！！\n");
		system("pause");
	}
}
void menu2()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		system("cls");
		printf("三子棋~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("==================================\n");
		printf("       1.play        0.exit       \n");
		printf("==================================\n");
		printf("请选择>:");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game2();
			break;
		case 0:
			printf("退出游戏\n");
		default:
			printf("错误输入！！！\n");
			break;
		}

	} while (input);
}
void test()
{
	system("title game v1.0");
	int input = 0;
	printf("==================================\n");
	printf("       1.扫雷        2.三子棋       \n");
	printf("==================================\n");
	do
	{
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			menu1();
			return 0;
		case 2:
			menu2();
		default:
			printf("选择错误！！！\n");
		}
	} while (input);
}
int main()
{

	test();
	return 0;
}