#ifndef __MAIL_H__
#define __MAIL_H__
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MAXSIZE 1000
int cnum;
typedef struct
{
	char name[MAXSIZE / 50];
	char sex[MAXSIZE / 500];
	char tel[MAXSIZE / 50];
	char address[MAXSIZE / 20];
	char age[MAXSIZE / 500 + 1];
}contact;
void Menu();
void AddContact(contact person[]);
void Disaply(contact person[]);
void DelectContact(contact person[]);
void Move(contact person[],int i);
void SearchContact(contact person[]);
void ReverseContact(contact person[]);
void EmptyContact(contact person[]);
void NameSortContact(contact person[]);
#endif

