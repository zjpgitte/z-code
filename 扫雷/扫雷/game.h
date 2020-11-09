#ifndef __GAME_H__
#define __GAME_H__
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#pragma warning(disable:4996)
#define ROW 12
#define COL 12
#define NUM 20
void game();
void Computer(char BombBoard[][COL]);
char Player(char ChesBoard[][COL], char BombBoard[][COL]);
void show(char board[][COL]);
#endif