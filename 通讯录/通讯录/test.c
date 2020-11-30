#include "main.h"
void InitContact(contact_t **contact)
{
	FILE *fp = fopen(FILE_TXT, "rb");
	if (NULL == fp)
	{
		printf("INIT FROM DEFAULT...\n");
		*contact = (contact_t *)malloc(sizeof(contact_t)+sizeof(person_t)*CAP);
		(*contact)->cap = CAP;
		(*contact)->size = 0;
		printf("INIT SUCCESS!\n");
	}
	else
	{
		printf("INIT FROM FILE...\n");
		contact_t p;
		fread(&p, sizeof(contact_t), 1, fp);
		*contact = (contact_t *)malloc(sizeof(contact_t)+sizeof(person_t)*(p.cap));
		(*contact)->size = fread((*contact)->person, sizeof(person_t), p.cap, fp);
		(*contact)->cap = p.cap;
		fclose(fp);
		printf("INIT SUCCESS!\n");
	}
}
static int IsFull(contact_t *contact)
{
	if (contact->size < contact->cap)
	{
		return 0;
	}
	else return 1;
}
static int Inc(contact_t **contact)
{
	contact_t *p = NULL;
	int num = (*contact)->cap;
	printf("INC ing >>>>>\n");
	p = (contact_t *)realloc((*contact),sizeof(contact_t)+(num + INC)*sizeof(person_t));
	if (p == NULL)
	{
		return 0;
	}
	*contact = p;
	(*contact)->cap = num + INC;
	printf("INC end >>>>>\n");
	return 1;
}
void InsertPerson(contact_t **contact)
{
	if (NULL == contact)
	{
		return;
	}
		if (!IsFull(*contact) || Inc(contact))//�漰���ռ����Ĵ�����ָ��
		{
			printf("������ϵ����Ϣ\n");
			printf("����:");
			scanf("%s", (*contact)->person[(*contact)->size].name);
			printf("�Ա�:");
			scanf("%s", (*contact)->person[(*contact)->size].sex);
			printf("����:");
			scanf("%s", (*contact)->person[(*contact)->size].age);
			printf("�绰:");
			scanf("%s", (*contact)->person[(*contact)->size].tel);
			printf("סַ:");
			scanf("%s", (*contact)->person[(*contact)->size].adres);

		}
		(*contact)->size += 1;
		printf("��ӳɹ�\n");

}
void Menu()
{
	printf("1.���                 2.ɾ��\n");
	printf("3.����                 4.�޸�\n");
	printf("5.�鿴                 6.���\n");
	printf("7.����                 0.�˳�\n");
}
void Disaply(contact_t *contact)
{
	if (NULL == contact)
	{
		return;
	}
	if (contact->size == 0)
	{
		printf("ͨѶ¼�գ�\n");
		return;
	}
	printf("%-20s%-20s\n", "����", "�绰");
	for (int i = 0; i < contact->size; i++)
	{
		printf("%-20s%-20s\n", contact->person[i].name, contact->person[i].tel);
	}
}
void Save(contact_t *contact)
{
	if (NULL == contact)
	{
		return;
	}
	FILE *fp = fopen(FILE_TXT, "wb");
	if (NULL == fp)
	{
		printf("open file error!\n");
		return;
	}
	fwrite(contact, sizeof(contact_t), 1, fp);
	fwrite(contact->person, sizeof(person_t), contact->size, fp);
	fclose(fp);
	printf("save success!\n");
}
int SearchPerson(contact_t *contact, char nam[])
{
	if (NULL == contact)
	{
		return -1;
	}
	int  i = 0;
	for (; i < contact->size; i++)
	{
		if (strcmp(nam, contact->person[i].name) == 0)
		{
			printf("%-20s%-20s\n", "����", "�绰");
			printf("%-20s%-20s\n", contact->person[i].name, contact->person[i].tel);
			return i;
		}
	}
	return -1;
}
void DelPerson(contact_t *contact)
{
	if (NULL == contact)
	{
		return;
	}
	else if (contact->size == 0)
	{
		printf("contact empty!\n");
		return;
	}
	else
	{
		printf("����ɾ��������");
		char nam[SIZE / 4];
		scanf("%s", nam);
		int pos = SearchPerson(contact, nam);
		contact->person[pos] = contact->person[contact->size - 1];
		contact->size -= 1;
	}
	printf("delect success!\n");
}
void ModifyPerson(contact_t *contact)
{
	if (NULL == contact)
	{
		return;
	}
	printf("��������:");
	char nam[SIZE / 4];
	scanf("%s", nam);
	int pos = SearchPerson(contact, nam);
	printf("�޸ĺ����Ϣ:");
	printf("����:");
	scanf("%s", contact->person[pos].name);
	printf("�Ա�:");
	scanf("%s", contact->person[pos].sex);
	printf("����:");
	scanf("%s", contact->person[pos].age);
	printf("�绰:");
	scanf("%s", contact->person[pos].tel);
	printf("סַ:");
	scanf("%s", contact->person[pos].adres);
	printf("%-20s%-20s\n", "����", "�绰");
	printf("%-20s%-20s\n", contact->person[pos].name, contact->person[pos].tel);
	
}
void ClearContact(contact_t *contact)
{
	if (NULL == contact)
	{
		return;
	}
	contact->size = 0;
	printf("clear success!\n");
}
void SortContact(contact_t *contact)
{
	if (NULL == contact)
	{
		return;
	}
	if (contact->size == 0)
	{
		printf("ͨѶ¼�գ�\n");
		return;
	}
	for (int i = 0; i < contact->size; i++)
	{
		int tag = 1;
		for (int j = 0; j < contact->size - 1 - i; j++)
		{
			person_t *p = contact->person;
			if (strcmp(p[j].name, p[j + 1].name) > 0)
			{
				person_t temp = p[j];
				p[j] = p[j + 1];
				p[j+1] = temp;
				tag = 0;
			}
		}
		if (tag == 1)
		{
			return;
		}
	}
	printf("sort success!\n");
}