#pragma once
#pragma once
#define ROW 3
#define COL 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

//��������
void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void Move(char board[ROW][COL], int row, int col);


//��������״̬Iswin();
//���Ӯ ��*��
//����Ӯ ��#��
//ƽ��   ��Q'
//����    'C'

char IsWin(char board[ROW][COL], int row, int col);