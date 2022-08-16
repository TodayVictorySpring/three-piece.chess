#pragma once
#pragma once
#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

//函数声明
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void Move(char board[ROW][COL], int row, int col);


//反馈四种状态Iswin();
//玩家赢 ‘*’
//电脑赢 ‘#’
//平局   ‘Q'
//继续    'C'

char IsWin(char board[ROW][COL], int row, int col);