//���������ģ��
#include<stdio.h>
#include"game.h"

void menu()
{
	printf_s("$$$$$$$$$$$$$$$$$$$$$$\n");
	printf_s("## 1.play    0.exit ##\n");
	printf_s("$$$$$$$$$$$$$$$$$$$$$$\n");
}
//��Ϸ�������㷨ʵ��
void game()
{
	char ret = 0;
	printf_s("Start the game!\n");
	//��������-����������Ϣ
	char board[ROW][COL] = { 0 };//ȫ���ո�
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	
	//����
	Move(board, ROW, COL);

	//�ɼ�
	ret = IsWin(board, ROW, COL);

	if (ret == '*')
	{
		printf("���ȻӮ�ˣ���\n");
	}
	else if (ret == '#')
	{
		printf("�ٺ٣�С������������\n");
	}
	else
	{
		printf("����\n");
	}
}
void test()
{
	int input = 0;

	srand((unsigned int)time(NULL));//???
	do
	{
		menu();
		printf_s("Please select a situation:> 1or0 ?\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf_s("game over...");
			break;
		default:
			break;
		}
	} while (input);//Ϊ��ѭ��������Ϊ�棩
}
int main()
{
	test();
	return 0;
}