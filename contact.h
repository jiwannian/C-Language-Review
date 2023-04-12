#pragma once
#include <stdio.h>
#include <windows.h>

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_STU_NUM 12
#define MAX_DATA 1000

struct Stu
{
	char name[MAX_NAME];

	char sex[MAX_SEX];

	char stu_num[MAX_STU_NUM];

};


struct Con
{
	struct Stu data[MAX_DATA];
	int size;
};

struct PS
{
	char password[0];
};

enum ELECT
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

void Initcnotact(struct Con* sc);

void AddContact(struct Con* ac);

void ShowContact(const struct Con* sc);

void DelContact(struct Con* dc);

void SearchContact(struct Con* sc);

void ModifyContact(struct Con* mc);

void SortContact(struct Con* sc);

void Password(struct PS* ps);