#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include "contact.h"


void menu()
{  
	printf("       21����1��ѧ����Ϣ        \n");
	printf("******************************\n");
	printf("*****1.add       2.del   *****\n");
	printf("*****3.search    4.modify*****\n");
	printf("*****5.show      6.sort  *****\n");
	printf("*****0.exit              *****\n");
	printf("******************************\n");
	printf("��ѡ��>:");
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
			printf("�Ƿ����룡����\n");
			system("pause");
			break;
		}
	} while (input);
	return 0;
}