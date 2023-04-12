#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include "contact.h"


void menu()
{  
	printf("       21电气1班学生信息        \n");
	printf("******************************\n");
	printf("*****1.add       2.del   *****\n");
	printf("*****3.search    4.modify*****\n");
	printf("*****5.show      6.sort  *****\n");
	printf("*****0.exit              *****\n");
	printf("******************************\n");
	printf("请选择>:");
}
int main()
{	
	struct PS ps;
	Password(&ps);
	int input = 0;
	struct Con con;
	Initcnotact(&con);

	do
	{
		menu();
		scanf("%d", &input);
		
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			break;
		default:
			printf("非法输入！！！\n");
			system("pause");
			break;
		}
	} while (input);
	return 0;
}