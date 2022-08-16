//三子棋测试模块
#include<stdio.h>
#include"game.h"

void menu()
{
	printf_s("$$$$$$$$$$$$$$$$$$$$$$\n");
	printf_s("## 1.play    0.exit ##\n");
	printf_s("$$$$$$$$$$$$$$$$$$$$$$\n");
}
//游戏的整个算法实现
void game()
{
	char ret = 0;
	printf_s("Start the game!\n");
	//创建数组-储存棋盘信息
	char board[ROW][COL] = { 0 };//全部空格
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	
	//下棋
	Move(board, ROW, COL);

	//成绩
	ret = IsWin(board, ROW, COL);

	if (ret == '*')
	{
		printf("你居然赢了？！\n");
	}
	else if (ret == '#')
	{
		printf("嘿嘿，小辣鸡你又输啦\n");
	}
	else
	{
		printf("和棋\n");
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
	} while (input);//为真循环（非零为真）
}
int main()
{
	test();
	return 0;
}