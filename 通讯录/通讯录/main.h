#ifndef __MAIN__H__
#define __MAIN__H__

#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)
#define SIZE 128//联系人的信息
#define CAP 1
#define INC 1
#define FILE_TXT "contact.txt"
typedef struct
{
	char name[SIZE / 4];
	char sex[SIZE / 32];
	char age[SIZE / 32];
	char tel[SIZE / 4];
	char adres[SIZE / 2];
}person_t;
typedef struct
{
	int cap;  //最大容量
	int size; //当前人数
	person_t person[0];//柔性数组，用于动态边长通讯录
}contact_t;
void InitContact(contact_t **contact);
void InsertPerson(contact_t *contact);
void Menu();
void Disaply(contact_t *contact);
void Save(contact_t *contact);
void DelPerson(contact_t *contact);
int SearchPerson(contact_t *contact,char nam[]);
void ModifyPerson(contact_t *contact);
void SortContact(contact_t *contact);
void ClearContact(contact_t *contact);
#endif