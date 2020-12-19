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
	int number;//代号
	char name[SIZE * 3];//名称
	char introduc[SIZE*10];//简介
}VertexDateType;//顶点
typedef struct
{
	int distance;
}ArcNodeType;//边
typedef struct
{
	VertexDateType vertex[SIZE];
	ArcNodeType arc[SIZE][SIZE];
	int vertexnum;
	int arcnum;
}AdjMartrix;//图
//初始化图
void DisaplyCampusGraph(AdjMartrix *G);
void InitCampusGraph(AdjMartrix *G);
void ModifyCampusGraph(AdjMartrix *G);//修改图中顶点和边的信息
void SearchVertexDate(AdjMartrix *G);//查询一个顶点的信息
void SearchArcDate(AdjMartrix *G);//查询一个边的信息(最短路径)
void Menu();
void DisaplyArc(AdjMartrix *G);//显示弧的信息
void DevelopOption(AdjMartrix *G);//开发人员选项
