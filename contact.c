#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include "contact.h"

void* m_memset(void* dast,int cor,int sz)
{
	void* ret = dast;
	while (sz--)
	{
		*(char*)dast = (char)cor;
		++(char*)dast;
	}
	return ret;
}
int m_strcmp(const char* p1, const char* p2)
{
	while (*p2&&!(*p1 - *p2))
	{
		p1++;
		p2++;
	}
	if ((*p1 - *p2) > 0)
		return 1;
	else if ((*p1 - *p2) < 0)
		return -1;
	else
		return 0;
}
void pause_cls()
{
	system("pause");
	system("cls");
}
static int Findbyname(struct Con* sc,char* name)
{
	for (int i = 0;i < sc->size;i++)
	{
		if (0 == m_strcmp(sc->data[i].name, name))
			return i;
	}
	return -1;
}
void Initcnotact(struct Con* sc)
{
	m_memset(sc->data, 0, sizeof(sc->data));
	sc->size = 0;
}

void AddContact(struct Con* ac)
{
	if (ac->size < MAX_DATA)
	{
		printf("����������>:");
		scanf("%s", ac->data[ac->size].name);

		printf("�������Ա�>:");
		scanf("%s", ac->data[ac->size].sex);

		printf("������ѧ��>:");
		scanf("%s", ac->data[ac->size].stu_num);
		 
		ac->size++;

		system("cls");
		printf("ѧ����Ϣ����ɹ�������\n");
		pause_cls();
		
	}
	else
		printf("���ݳ�����Χ������\n");
}

void ShowContact(const struct Con* sc)
{
	printf("%-4s\t%-10s\t%-5s\t%-11s\n", "���", "����", "�Ա�", "ѧ��");
	for (int i = 0;i < sc->size;i++)
	{
		if (sc->size < MAX_DATA)
		{
			printf("%-1d\t%-10s\t%-5s\t%-11s\n", i + 1,
				sc->data[i].name,
				sc->data[i].sex,
				sc->data[i].stu_num);
		}
		else
		{
			printf("���ݳ�����Χ������\n");
			pause_cls();
		}
	}
	pause_cls();
}

void DelContact(struct Con* dc)
{
	char name[MAX_NAME];
	printf("������Ҫɾ��ѧ����Ϣ������>:");
	scanf("%s", &name);
	int ret = Findbyname(dc,name);
	if (ret == -1)
	{
		printf("�޴�ѧ����Ϣ������\n");
		pause_cls();
	}
	else
	{
		for (int i = ret;i < dc->size;i++)
		{
			dc->data[i] = dc->data[i + 1];
		}
		dc->size--;
		system("cls");
		printf("����ɾ���ɹ�������\n");
		pause_cls();
	}
}

void SearchContact(struct Con* sc)
{
	char name[MAX_NAME];
	printf("������ѧ������>:");
	scanf("%s", &name);
	int ret = Findbyname(sc, name);
	if (ret == -1)
	{
		printf("�޴�ѧ����Ϣ������\n");
		pause_cls();
	}
	else
	{
		printf("%-4s\t%-10s\t%-5s\t%-11s\n", "���", "����", "�Ա�", "ѧ��");
		printf("%-1d\t%-10s\t%-5s\t%-11s\n", ret+1,
			sc->data[ret].name,
			sc->data[ret].sex,
			sc->data[ret].stu_num);
		pause_cls();
	}
}

void ModifyContact(struct Con* mc)
{
	char name[MAX_NAME];
	printf("���������޸���Ϣѧ��������>:");
	scanf("%s", &name);
	system("cls");
	int ret = Findbyname(mc, name);
	if (ret == -1)
	{
		printf("�޴�ѧ����Ϣ������\n");
		pause_cls();
	}
	else
	{
		printf("�������޸ĺ������>:");
		scanf("%s", mc->data[ret].name);

		printf("�������޸ĺ���Ա�>:");
		scanf("%s", mc->data[ret].sex);

		printf("�������޸ĺ��ѧ��>:");
		scanf("%s", mc->data[ret].stu_num);

		system("cls");
		printf("ѧ����Ϣ�޸ĳɹ�������\n");
		pause_cls();
	}
}


int cmp(struct Stu s1, struct Stu s2,int* input,int* put)
{
	if (*input == 0)
	{
		if (*put == 0)
		{
			if (m_strcmp(s1.name, s2.name) > 0)
			{
				return 1;
			}
		
			else
				return -1;
		}
		else
		{
			if (m_strcmp(s1.name, s2.name) < 0)
				return 1;
			else
				return -1;
		}
	}
	else
	{
		if (*put == 0)
		{
			if (m_strcmp(s1.stu_num, s2.stu_num) > 0)
				return 1;
			else
				return -1;
		}
		else
		{
			if (m_strcmp(s1.stu_num, s2.stu_num) < 0)
				return 1;
			else
				return -1;
		}
	}
}

void Sort(struct Con* stu,int* input,int* put)
{
	int i = 0;
	
	for (i = 0;i < stu->size-1;i++)
	{
		int j = 0;
		for (j = 0;j < stu->size-1 - i;j++)
		{
			if (cmp(stu->data[j], stu->data[j + 1],input,put) > 0)
			{
				struct Stu tmp;
				tmp = stu->data[j];
				stu->data[j] = stu->data[j + 1];
				stu->data[j + 1] = tmp;
			}
		}
	}
	printf("������ɣ�����\n");
	pause_cls();


}

void SortContact(struct Con* sc)
{
	int input = 0;
	int put = 0;
	printf("����������ʽ(0.����/1.ѧ��)>:");
	scanf("%d", &input);
	printf("����������ʽ(0.��С����/1.�Ӵ�С)>:");
	scanf("%d", &put);
	Sort(sc, &input, &put);

}

void Password(struct PS* ps)
{
	char input[5];
	while (1)
	{
		printf("������ʹ������>:");
		scanf("%s", &input);
		if (m_strcmp(input, "0000") == 0)
		{
			printf("������ȷ!\n");
			system("pause");
			break;
		}
		else
			printf("����������������룡����\n");
		pause_cls();
	}
	system("cls");
}
