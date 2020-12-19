#pragma once
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#pragma warning(disable:4996)
#define INFINITY 32468
#define SIZE 12
typedef struct 
{
	int number;//����
	char name[SIZE * 3];//����
	char introduc[SIZE*10];//���
}VertexDateType;//����
typedef struct
{
	int distance;
}ArcNodeType;//��
typedef struct
{
	VertexDateType vertex[SIZE];
	ArcNodeType arc[SIZE][SIZE];
	int vertexnum;
	int arcnum;
}AdjMartrix;//ͼ
//��ʼ��ͼ
void DisaplyCampusGraph(AdjMartrix *G);
void InitCampusGraph(AdjMartrix *G);
void ModifyCampusGraph(AdjMartrix *G);//�޸�ͼ�ж���ͱߵ���Ϣ
void SearchVertexDate(AdjMartrix *G);//��ѯһ���������Ϣ
void SearchArcDate(AdjMartrix *G);//��ѯһ���ߵ���Ϣ(���·��)
void Menu();
void DisaplyArc(AdjMartrix *G);//��ʾ������Ϣ
void DevelopOption(AdjMartrix *G);//������Աѡ��
