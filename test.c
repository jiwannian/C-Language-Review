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
		printf("ɨ��~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("==================================\n");
		printf("       1.play        0.exit       \n");
		printf("==================================\n");
		printf("��ѡ��>:");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game1();
			break;
		case 0:
			printf("�˳���Ϸ\n");
		default:
			printf("�������룡����\n");
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
		printf("��ϲ�㣬��Ӯ�ˣ�����\n");
		system("pause");
	}
	else if (judg_win(board, ROW2, COL2) == '#')
	{
		printf("����������ⶼ����!!!\n");
		system("pause");
	}
	else
	{
		printf("ƽ�֣�����\n");
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
		printf("������~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("==================================\n");
		printf("       1.play        0.exit       \n");
		printf("==================================\n");
		printf("��ѡ��>:");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game2();
			break;
		case 0:
			printf("�˳���Ϸ\n");
		default:
			printf("�������룡����\n");
			break;
		}

	} while (input);
}
void test()
{
	system("title game v1.0");
	int input = 0;
	printf("==================================\n");
	printf("       1.ɨ��        2.������       \n");
	printf("==================================\n");
	do
	{
		printf("��ѡ��>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			menu1();
			return 0;
		case 2:
			menu2();
		default:
			printf("ѡ����󣡣���\n");
		}
	} while (input);
}
int main()
{

	test();
	return 0;
}