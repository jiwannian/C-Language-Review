#pragma once
#define ROW1 9
#define COL1 9
#define ROW2 3
#define COL2 3
#define ROWS 11
#define COLS 11
#define MINE_COUNT 10


#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>

void Initboard1(char board[ROWS][COLS],int rows,int cols,char set);
void Playboard(char board[ROWS][COLS], int row1, int col1);
void Setmine(char mine[ROWS][COLS],int row1,int col1);
void Findmine(char mine[ROWS][COLS],char show[ROWS][COLS],int row1,int col1);

void Initboard2(char board[ROW2][COL2], int row2, int col2);
void Playboard2(char board[ROW2][COL2], int row2, int col2);
void player_set(char board[ROW2][COL2], int row2, int col2);
void conputer_set(char board[ROW2][COL2], int row2, int col2);
char judg_win(char board[ROW2][COL2], int row2, int col2);