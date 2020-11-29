#include "mail.h"
//�����ϵ����Ϣ
//ɾ��ָ����ϵ����Ϣ
//����ָ����ϵ����Ϣ
//�޸�ָ����ϵ����Ϣ
//��ʾ������ϵ����Ϣ
//���������ϵ��
//����������������ϵ��
//�������Ա����䡢�绰��סַ
void Menu()
{
	printf("1.�����ϵ��\n");
	printf("2.ɾ����ϵ��\n");
	printf("3.������ϵ��\n");
	printf("4.�޸���ϵ��\n");
	printf("5.��ʾ��ϵ��\n");
	printf("6.�����ϵ��\n");
	printf("7.����������\n");
	printf("0.�˳�\n");
}
void AddContact(contact person[])
{
	if (cnum == MAXSIZE)
	{
		printf("ͨѶ¼����\n");
		return;
	}
	while (1)
	{
		if (cnum < MAXSIZE)
		{
			printf("����������#\n");
			gets(person[cnum].name);
			printf("�������Ա�#\n");
			gets(person[cnum].sex);		
			printf("����������#\n");
			gets(person[cnum].age);
			printf("������绰#\n");
			gets(person[cnum].tel);
			printf("������סַ#\n");
			gets(person[cnum].address);
			cnum++;
			printf("������\n");
			break;
		}
		else
		{
			printf("����������#");
		}
	}
}
void Disaply(contact person[])
{
	if (NULL == person || cnum ==0)
	{
		printf("ͨ��¼��\n");
		return;
	}
	    printf("����                  �Ա� ����     �绰           ��ַ\n");
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
		printf("ͨ��¼��\n");
		return;
	}
	printf("��������ϵ������#");
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
		printf("ͨ��¼��\n");
		return;
	}
	printf("����������#\n");
	char nam[20];
	gets(nam);
	for (int i = 0; i < cnum; i++)
	{
		if (strcmp(nam, person[i].name) == 0)
		{
			printf("����                �Ա�   ����    �绰      ��ַ\n");
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
		printf("ͨ��¼��\n");
		return;
	}
	printf("�������޸�������#");
	char nam[20];
	gets(nam);
	for (int i = 0; i < cnum; i++)
	{
		if (strcmp(nam, person[i].name) == 0)
		{
			printf("�������޸ĺ����Ϣ\n");
			printf("����������#\n");
			gets(person[i].name);
			printf("�������Ա�#\n");
			gets(person[i].sex);
			printf("����������#\n");
			gets(person[i].age);
			printf("������绰#\n");
			gets(person[i].tel);
			printf("������סַ#\n");
			gets(person[i].address);
			printf("�޸����\n");
			return;
		}
	}
	printf("find error!\n");
}
void EmptyContact(contact person[])
{
	if (NULL == person || cnum == 0)
	{
		printf("ͨѶ¼�ѿ�\n");
		return;
	}
	cnum = 0;
	printf("clear success!\n");
}
void NameSortContact(contact person[])
{
	if (cnum == 0)
	{
		printf("ͨѶ¼�ѿ�\n");
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
