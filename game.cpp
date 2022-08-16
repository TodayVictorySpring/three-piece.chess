#include "game.h"

//函数实现

//初始化棋盘数据
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)//对一整大行
	{
		//打印其中第一小行
		for (j = 0; j < col - 1; j++)
		{
			printf_s(" %c |", board[i][j]);
		}
		printf_s(" %c \n", board[i][col - 1]);
		//打印其中第一小行
		if (i < row - 1)
		{
			for (j = 0; j < col - 1; j++)
			{
				printf_s("---|");
			}
			printf_s("---\n");
		}
	}
}
//注：数组的角标可以访问某元素的值，但是这并不决定元素的位置。将一个二维数组排成一排也毫无问题



//下棋
void Move(char board[ROW][COL], int row, int col)
{
	//创建数组储存棋子信息
	int px[5] = { 0 };
	int py[5] = { 0 };//玩家信息

	int cx[4] = { 0 };
	int cy[4] = { 0 };//电脑信息

	for (int i = 0; i < 5; i++)
	{
		//玩家下棋
		printf_s("玩家走:>\n");
		while (1)
		{			
			printf_s("请输入您的坐标:");
			scanf_s("%d%d", &px[i], &py[i]);
			//判断x,y的合法性
			if (px[i] >= 1 && px[i] <= row && py[i] >= 1 && py[i] <=col)//是否满足条件输入坐标合法
			{
				if (board[px[i]-1][py[i]-1] == ' ')//是否满足条件在未落子的地方落子
				{
					board[px[i]-1][py[i]-1] = '*';
					break;
				}
				else
				{
					printf("该坐标已被占用，请重新输入！\n");//不满足，将直接跳出两个if语句，再次进入while循环					
				}
			}
			else
			{
				printf_s("您所输坐标不合理，请您重新输入!\n");//不满足，再次进入while循环				
			}
		}

		DisplayBoard(board, ROW, COL);

		//判断输赢
		char ret = 0;
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		
		//电脑下棋
		
		printf("电脑走:>\n");
		if (i < 4) 
		{
			//电脑的第一步
			if (i == 0)
			{				
				//情况一
				if (px[i] == 2 && py[i] == 2)
				{	
					while (1)
					{
						cx[i] = 2 * (rand() % 2)+1;
						cy[i] = 2 * (rand() % 2)+1;
						if (board[cx[i]-1][cy[i]-1] == ' ')
						{
							board[cx[i]-1][cy[i]-1] = '#';
							break;
						}
					}										
				}	
				//情况二
				else
				{
					cx[i] = 2;
					cy[i] = 2;
					board[cx[i]-1][cy[i]-1] = '#';
				}
			}
			//电脑的第二步及以上
			else
			{
				int j = 0;
				int p = 0;

				int a = 0;
				int b = 0;
				int m = 0;
				int n = 0;

				int max = 0;
				int min = 0;

				int topx = 0;
				int topy = 0;
				int bottomx = 0;
				int bottomy = 0;

				//从第三步开始，先自我判断

				if (i >= 2)
				{
					for (int j = 0; j < i - 1; j++)
					{
						for (int p = 1; p <= i - 1; p++)
						{
							if (p + j == i - 1)
							{
								a = abs(cy[j + p] - cy[j]);
								b = abs(cx[j + p] - cx[j]);

								m = cy[j + p] - cy[j];//间隔一次的坐标值之差
								n = cx[j + p] - cx[j];

								//情况一
								//最上端+1或最下端-1。如果是五子棋的话，可以先排序，找出坐标最值，再递增（间距不一定是一）
								if (b == 0 && a == 1)//横排
								{
									if (m > 0)
									{
										max = cy[j + p];
										min = cy[j];
									}
									else
									{
										max = cy[j];
										min = cy[j + p];
									}
									cx[i] = px[j];
									cy[i] = max + 1;
									if (board[cx[i] - 1][cy[i] - 1] == ' ' && cx[i] >= 1 && cx[i] <= row && cy[i] >= 1 && cy[i] <= col)
									{
										board[cx[i] - 1][cy[i] - 1] = '#';
										break;
									}
									else
									{
										cx[i] = cx[j];
										cy[i] = min - 1;
										if (board[cx[i] - 1][cy[i] - 1] == ' ' && cx[i] >= 1 && cx[i] <= row && cy[i] >= 1 && cy[i] <= col)
										{
											board[cx[i] - 1][cy[i] - 1] = '#';
											break;
										}
										else
										{
											cx[i] = 0;
											cy[i] = 0;
										}
									}
								}
								if (b == 1 && a == 0)//竖排
								{
									if (n > 0)
									{
										max = cx[j + p];
										min = cx[j];
									}
									else
									{
										max = cx[j];
										min = cx[j + p];
									}
									cx[i] = max + 1;
									cy[i] = cy[j];
									if (board[cx[i] - 1][cy[i] - 1] == ' ' && cx[i] >= 1 && cx[i] <= row && cy[i] >= 1 && cy[i] <= col)
									{
										board[cx[i] - 1][cy[i] - 1] = '#';
										break;
									}
									else
									{
										cx[i] = min - 1;
										cy[i] = cy[j];
										if (board[cx[i] - 1][cy[i] - 1] == ' ' && cx[i] >= 1 && cx[i] <= row && cy[i] >= 1 && cy[i] <= col)
										{
											board[cx[i] - 1][cy[i] - 1] = '#';
											break;
										}
										else
										{
											cx[i] = 0;
											cy[i] = 0;
										}
									}
								}
								//情况二
								if (m == n && a == 1)
								{
									if (m > 0)
									{
										bottomx = cx[j + p];
										bottomy = cy[j + p];

										topx = cx[j];
										topy = cy[j];
									}
									else
									{
										bottomx = cx[j];
										bottomy = cy[j];

										topx = cx[j + p];
										topy = cy[j + p];
									}
									cx[i] = topx - 1;
									cy[i] = topy - 1;
									if (board[cx[i] - 1][cy[i] - 1] == ' ' && cx[i] >= 1 && cx[i] <= row && cy[i] >= 1 && cy[i] <= col)
									{
										board[cx[i] - 1][cy[i] - 1] = '#';
										break;
									}
									else
									{
										cx[i] = bottomx + 1;
										cy[i] = bottomy + 1;
										if (board[cx[i] - 1][cy[i] - 1] == ' ' && cx[i] >= 1 && cx[i] <= row && cy[i] >= 1 && cy[i] <= col)
										{
											board[cx[i] - 1][cy[i] - 1] = '#';
											break;
										}
										else
										{
											cx[i] = 0;
											cy[i] = 0;
										}
									}
								}
								if (-n == m && a == 1)
								{
									if (m > 0)
									{
										bottomx = cx[j];
										bottomy = cy[j];

										topx = cx[j + p];
										topy = cy[j + p];
									}
									else
									{
										bottomx = cx[j + p];
										bottomy = cy[j + p];

										topx = cx[j];
										topy = cy[j];
									}
									cx[i] = topx - 1;
									cy[i] = topy + 1;
									if (board[cx[i] - 1][cy[i] - 1] == ' ' && cx[i] >= 1 && cx[i] <= row && cy[i] >= 1 && cy[i] <= col)
									{
										board[cx[i] - 1][cy[i] - 1] = '#';
										break;
									}
									else
									{
										cx[i] = bottomx + 1;
										cy[i] = bottomy - 1;
										if (board[cx[i] - 1][cy[i] - 1] == ' ' && cx[i] >= 1 && cx[i] <= row && cy[i] >= 1 && cy[i] <= col)
										{
											board[cx[i] - 1][cy[i] - 1] = '#';
											break;
										}
										else
										{
											cx[i] = 0;
											cy[i] = 0;
										}
									}
								}
								//情况三
								if (b == 0 && a == 2)
								{
									cx[i] = cx[j + p];
									cy[i] = (cy[j] + cy[j + p]) / 2;
									if (board[cx[i] - 1][cy[i] - 1] == ' ' && cx[i] >= 1 && cx[i] <= row && cy[i] >= 1 && cy[i] <= col)
									{
										board[cx[i] - 1][cy[i] - 1] = '#';
										break;
									}
									else
									{
										cx[i] = 0;
										cy[i] = 0;
									}
								}
								if (a == 0 && b == 2)
								{
									cy[i] = cy[j + p];
									cx[i] = (cx[j] + cx[j + p]) / 2;
									if ((board[cx[i] - 1][cy[i] - 1] == ' ' && cx[i] >= 1 && cx[i] <= row && cy[i] >= 1 && cy[i] <= col))
									{
										board[cx[i] - 1][cy[i] - 1] = '#';
										break;
									}
									else
									{
										cx[i] = 0;
										cy[i] = 0;
									}
								}
								//情况四
								if (a == b && a == 2)
								{
									cx[i] = 2 * cx[j + p] - cx[j];
									cy[i] = 2 * cy[j + p] - cy[j];
									if ((board[cx[i] - 1][cy[i] - 1] == ' ' && cx[i] >= 1 && cx[i] <= row && cy[i] >= 1 && cy[i] <= col))
									{
										board[cx[i] - 1][cy[i] - 1] = '#';
										break;
									}
									else
									{
										cx[i] = 0;
										cy[i] = 0;
									}
								}
							}
						}
						if (cx[i] != 0 && cy[i] != 0)
						{
							break;
						}
					}
				}
				//堵
				if (cx[i] == 0 && cy[i] == 0)
				{
					for (j = 0; j < i; j++)
					{
						for (p = 1; p <= i; p++)
						{
							if (j + p == i)
							{
								a = abs(py[j + p] - py[j]);
								b = abs(px[j + p] - px[j]);

								m = py[j + p] - py[j];//间隔一次的坐标值之差
								n = px[j + p] - px[j];

								//情况一
								//最上端+1或最下端-1。如果是五子棋的话，可以先排序，找出坐标最值，再递增（间距不一定是一）
								if (b == 0 && a == 1)//横排
								{
									if (m > 0)
									{
										max = py[j + p];
										min = py[j];
									}
									else
									{
										max = py[j];
										min = py[j + p];
									}
									cx[i] = px[j];
									cy[i] = max + 1;
									if (board[cx[i] - 1][cy[i] - 1] == ' ' && cx[i] >= 1 && cx[i] <= row && cy[i] >= 1 && cy[i] <= col)//注意了
									{
										board[cx[i] - 1][cy[i] - 1] = '#';
										break;
									}
									else
									{
										cx[i] = px[j];
										cy[i] = min - 1;
										if (board[cx[i] - 1][cy[i] - 1] == ' ' && cx[i] >= 1 && cx[i] <= row && cy[i] >= 1 && cy[i] <= col)
										{
											board[cx[i] - 1][cy[i] - 1] = '#';
											break;
										}
										else
										{
											cx[i] = 0;
											cy[i] = 0;
										}
									}
								}
								if (b == 1 && a == 0)//竖排
								{
									if (n > 0)
									{
										max = px[j + p];
										min = px[j];
									}
									else
									{
										max = px[j];
										min = px[j + p];
									}
									cx[i] = max + 1;
									cy[i] = py[j];
									if (board[cx[i] - 1][cy[i] - 1] == ' ' && cx[i] >= 1 && cx[i] <= row && cy[i] >= 1 && cy[i] <= col)
									{
										board[cx[i] - 1][cy[i] - 1] = '#';
										break;
									}
									else
									{
										cx[i] = min - 1;
										cy[i] = py[j];
										if (board[cx[i] - 1][cy[i] - 1] == ' ' && cx[i] >= 1 && cx[i] <= row && cy[i] >= 1 && cy[i] <= col)
										{
											board[cx[i] - 1][cy[i] - 1] = '#';
											break;
										}
										else
										{
											cx[i] = 0;
											cy[i] = 0;
										}
									}
								}
								//情况二
								if (m == n && a == 1)
								{
									if (m > 0)
									{
										bottomx = px[j + p];
										bottomy = py[j + p];

										topx = px[j];
										topy = py[j];
									}
									else
									{
										bottomx = px[j];
										bottomy = py[j];

										topx = px[j + p];
										topy = py[j + p];
									}
									cx[i] = topx - 1;
									cy[i] = topy - 1;
									if (board[cx[i] - 1][cy[i] - 1] == ' ' && cx[i] >= 1 && cx[i] <= row && cy[i] >= 1 && cy[i] <= col)
									{
										board[cx[i] - 1][cy[i] - 1] = '#';
										break;
									}
									else
									{
										cx[i] = bottomx + 1;
										cy[i] = bottomy + 1;
										if (board[cx[i] - 1][cy[i] - 1] == ' ' && cx[i] >= 1 && cx[i] <= row && cy[i] >= 1 && cy[i] <= col)
										{
											board[cx[i] - 1][cy[i] - 1] = '#';
											break;
										}
										else
										{
											cx[i] = 0;
											cy[i] = 0;
										}
									}
								}
								if (-n == m && a == 1)
								{
									if (m > 0)
									{
										bottomx = px[j];
										bottomy = py[j];

										topx = px[j + p];
										topy = py[j + p];
									}
									else
									{
										bottomx = px[j + p];
										bottomy = py[j + p];

										topx = px[j];
										topy = py[j];
									}
									cx[i] = topx - 1;
									cy[i] = topy + 1;
									if (board[cx[i] - 1][cy[i] - 1] == ' ' && cx[i] >= 1 && cx[i] <= row && cy[i] >= 1 && cy[i] <= col)
									{
										board[cx[i] - 1][cy[i] - 1] = '#';
										break;
									}
									else
									{
										cx[i] = bottomx + 1;
										cy[i] = bottomy - 1;
										if (board[cx[i] - 1][cy[i] - 1] == ' ' && cx[i] >= 1 && cx[i] <= row && cy[i] >= 1 && cy[i] <= col)
										{
											board[cx[i] - 1][cy[i] - 1] = '#';
											break;
										}
										else
										{
											cx[i] = 0;
											cy[i] = 0;
										}
									}
								}
								//情况三
								if (b == 0 && a == 2)
								{
									cx[i] = px[j + p];
									cy[i] = (py[j] + py[j + p]) / 2;
									if (board[cx[i] - 1][cy[i] - 1] == ' ' && cx[i] >= 1 && cx[i] <= row && cy[i] >= 1 && cy[i] <= col)
									{
										board[cx[i] - 1][cy[i] - 1] = '#';
										break;
									}
									else
									{
										cx[i] = 0;
										cy[i] = 0;
									}
								}
								if (a == 0 && b == 2)
								{
									cy[i] = py[j + p];
									cx[i] = (px[j] + px[j + p]) / 2;
									if (board[cx[i] - 1][cy[i] - 1] == ' ' && cx[i] >= 1 && cx[i] <= row && cy[i] >= 1 && cy[i] <= col)
									{
										board[cx[i] - 1][cy[i] - 1] = '#';
										break;
									}
									else
									{
										cx[i] = 0;
										cy[i] = 0;
									}
								}
								//情况四
								if (a == b && a == 2)
								{
									cx[i] = 2 * px[j + p] - px[j];
									cy[i] = 2 * py[j + p] - py[j];
									if (board[cx[i] - 1][cy[i] - 1] == ' ' && cx[i] >= 1 && cx[i] <= row && cy[i] >= 1 && cy[i] <= col)
									{
										board[cx[i] - 1][cy[i] - 1] = '#';
										break;
									}
									else
									{
										cx[i] = 0;
										cy[i] = 0;
									}
								}
							}
						}
						if (cx[i] != 0 && cy[i] != 0)
						{
							break;
						}
					}
				}
												
				//如果以上全部行不通，则生成随机数
				if (cx[i] == 0 && cy[i] == 0)
				{
					while (1)
					{
						cx[i] = rand() % row;
						cy[i] = rand() % col;//生成随机数的方法
						if (board[cx[i]][cy[i]] == ' ')
						{
							board[cx[i]][cy[i]] = '#';
							break;
						}
					}
				}
			}			
		}

		DisplayBoard(board, ROW, COL);

		//判断输赢
		
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}	
}

//判断是否平局
char IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//判断行三行是否相等
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
		{
			return board[i][2];
		}
	}
	//判断竖三行是否相等
	for (i = 0; i < row; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ')
		{
			return board[2][i];
		}
	}
	//判断两个斜对角
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')
	{
		return board[2][2];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[0][2] != ' ')
	{
		return board[0][2];
	}
	//以上都不满足，则要么继续要么平局
	//判断是否平局
	if (IsFull(board, ROW, COL) == 1)
	{
		return'Q';
	}
	return 'C';
}
