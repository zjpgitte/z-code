#include "mail.h"
//添加联系人信息
//删除指定联系人信息
//查找指定联系人信息
//修改指定联系人信息
//显示所有联系人信息
//清空所有联系人
//以名字排序所有联系人
//姓名、性别、年龄、电话、住址
void Menu()
{
	printf("1.添加联系人\n");
	printf("2.删除联系人\n");
	printf("3.查找联系人\n");
	printf("4.修改联系人\n");
	printf("5.显示联系人\n");
	printf("6.清空联系人\n");
	printf("7.按姓名排序\n");
	printf("0.退出\n");
}
void AddContact(contact person[])
{
	if (cnum == MAXSIZE)
	{
		printf("通讯录已满\n");
		return;
	}
	while (1)
	{
		if (cnum < MAXSIZE)
		{
			printf("请输入姓名#\n");
			gets(person[cnum].name);
			printf("请输入性别#\n");
			gets(person[cnum].sex);		
			printf("请输入年龄#\n");
			gets(person[cnum].age);
			printf("请输入电话#\n");
			gets(person[cnum].tel);
			printf("请输入住址#\n");
			gets(person[cnum].address);
			cnum++;
			printf("添加完成\n");
			break;
		}
		else
		{
			printf("请重新输入#");
		}
	}
}
void Disaply(contact person[])
{
	if (NULL == person || cnum ==0)
	{
		printf("通信录空\n");
		return;
	}
	    printf("姓名                  性别 年龄     电话           地址\n");
	for (int i = 0; i < cnum; i++)
	{
		printf("%-20s  %-2s    %-3s  %-12s%-20s\n", person[i].name, person[i].sex, person[i].age, person[i].tel, person[i].address);
	}
}
void Move(contact person[],int i)
{
	while (i < cnum-1)
	{
		person[i] = person[i + 1];
		i++;
	}
}
void DelectContact(contact person[])
{
	if (NULL == person || cnum == 0)
	{
		printf("通信录空\n");
		return;
	}
	printf("请输入联系人姓名#");
	char nam[20];
	gets(nam);
	for (int i = 0; i < cnum; i++)
	{
		if (strcmp(nam, person[i].name) == 0)
		{
			Move(person,i);
			cnum--;
			printf("delect success!\n");
			return;
		}
	}
	printf("find error\n");
}
void SearchContact(contact person[])
{
	if (NULL == person || cnum == 0)
	{
		printf("通信录空\n");
		return;
	}
	printf("请输入姓名#\n");
	char nam[20];
	gets(nam);
	for (int i = 0; i < cnum; i++)
	{
		if (strcmp(nam, person[i].name) == 0)
		{
			printf("姓名                性别   年龄    电话      地址\n");
			printf("%-20s  %-2s    %-3s  %-12s%-20s\n", person[i].name, person[i].sex, person[i].age, person[i].tel, person[i].address);
			return;
		}
	}
	printf("find error!\n");
}
void ReverseContact(contact person[])
{
	if (NULL == person || cnum == 0)
	{
		printf("通信录空\n");
		return;
	}
	printf("请输入修改人姓名#");
	char nam[20];
	gets(nam);
	for (int i = 0; i < cnum; i++)
	{
		if (strcmp(nam, person[i].name) == 0)
		{
			printf("请输入修改后的信息\n");
			printf("请输入姓名#\n");
			gets(person[i].name);
			printf("请输入性别#\n");
			gets(person[i].sex);
			printf("请输入年龄#\n");
			gets(person[i].age);
			printf("请输入电话#\n");
			gets(person[i].tel);
			printf("请输入住址#\n");
			gets(person[i].address);
			printf("修改完成\n");
			return;
		}
	}
	printf("find error!\n");
}
void EmptyContact(contact person[])
{
	if (NULL == person || cnum == 0)
	{
		printf("通讯录已空\n");
		return;
	}
	cnum = 0;
	printf("clear success!\n");
}
void NameSortContact(contact person[])
{
	if (cnum == 0)
	{
		printf("通讯录已空\n");
		return;
	}
	for (int i = 0; i < cnum - 1; i++)
	{
		int quit = 0;
		for (int j = 0; j < cnum - 1 - i; j++)
		{
			if (strcmp(person[j].name, person[j + 1].name) > 0)
			{
				contact temp = person[j];
				person[j] = person[j + 1];
				person[j + 1] = temp;
				quit = 1;
			}
		}
		if (0 == quit)
		{
			break;
		}
	}
	printf("sort success!\n");
}
void SaveContact(contact person[])
{
	if (NULL == person)
	{
		return;
	}
	FILE *fp = fopen("contact.txt", "wb");
	if (NULL == fp)
	{ 
		printf("open file error!\n");
		return;
	}
	fwrite(person, sizeof(contact), cnum, fp);
	fclose(fp);
	printf("save success!\n");
}
void InitContact(contact person[])
{
	if (NULL == person)
	{
		return;
	}
	FILE *fp = fopen("contact.txt", "rb");
	if (NULL == fp)
	{
		printf("open error!\n");
		return;
	}
	int n = 0;
	cnum = fread(person, sizeof(contact), MAXSIZE, fp);
	/*while ((n=fread(person, sizeof(contact), 2, fp)) >= 2)
	{
		cnum += 2;
	}
	if (n == 1)
	{
		cnum++;
	}*/
	fclose(fp);
	printf("init success!\n");
}
