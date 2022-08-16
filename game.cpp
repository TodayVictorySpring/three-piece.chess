#include "game.h"

//����ʵ��

//��ʼ����������
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
//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)//��һ������
	{
		//��ӡ���е�һС��
		for (j = 0; j < col - 1; j++)
		{
			printf_s(" %c |", board[i][j]);
		}
		printf_s(" %c \n", board[i][col - 1]);
		//��ӡ���е�һС��
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
//ע������ĽǱ���Է���ĳԪ�ص�ֵ�������Ⲣ������Ԫ�ص�λ�á���һ����ά�����ų�һ��Ҳ��������



//����
void Move(char board[ROW][COL], int row, int col)
{
	//�������鴢��������Ϣ
	int px[5] = { 0 };
	int py[5] = { 0 };//�����Ϣ

	int cx[4] = { 0 };
	int cy[4] = { 0 };//������Ϣ

	for (int i = 0; i < 5; i++)
	{
		//�������
		printf_s("�����:>\n");
		while (1)
		{			
			printf_s("��������������:");
			scanf_s("%d%d", &px[i], &py[i]);
			//�ж�x,y�ĺϷ���
			if (px[i] >= 1 && px[i] <= row && py[i] >= 1 && py[i] <=col)//�Ƿ�����������������Ϸ�
			{
				if (board[px[i]-1][py[i]-1] == ' ')//�Ƿ�����������δ���ӵĵط�����
				{
					board[px[i]-1][py[i]-1] = '*';
					break;
				}
				else
				{
					printf("�������ѱ�ռ�ã����������룡\n");//�����㣬��ֱ����������if��䣬�ٴν���whileѭ��					
				}
			}
			else
			{
				printf_s("���������겻����������������!\n");//�����㣬�ٴν���whileѭ��				
			}
		}

		DisplayBoard(board, ROW, COL);

		//�ж���Ӯ
		char ret = 0;
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		
		//��������
		
		printf("������:>\n");
		if (i < 4) 
		{
			//���Եĵ�һ��
			if (i == 0)
			{				
				//���һ
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
				//�����
				else
				{
					cx[i] = 2;
					cy[i] = 2;
					board[cx[i]-1][cy[i]-1] = '#';
				}
			}
			//���Եĵڶ���������
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

				//�ӵ�������ʼ���������ж�

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

								m = cy[j + p] - cy[j];//���һ�ε�����ֵ֮��
								n = cx[j + p] - cx[j];

								//���һ
								//���϶�+1�����¶�-1�������������Ļ��������������ҳ�������ֵ���ٵ�������಻һ����һ��
								if (b == 0 && a == 1)//����
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
								if (b == 1 && a == 0)//����
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
								//�����
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
								//�����
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
								//�����
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
				//��
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

								m = py[j + p] - py[j];//���һ�ε�����ֵ֮��
								n = px[j + p] - px[j];

								//���һ
								//���϶�+1�����¶�-1�������������Ļ��������������ҳ�������ֵ���ٵ�������಻һ����һ��
								if (b == 0 && a == 1)//����
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
									if (board[cx[i] - 1][cy[i] - 1] == ' ' && cx[i] >= 1 && cx[i] <= row && cy[i] >= 1 && cy[i] <= col)//ע����
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
								if (b == 1 && a == 0)//����
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
								//�����
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
								//�����
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
								//�����
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
												
				//�������ȫ���в�ͨ�������������
				if (cx[i] == 0 && cy[i] == 0)
				{
					while (1)
					{
						cx[i] = rand() % row;
						cy[i] = rand() % col;//����������ķ���
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

		//�ж���Ӯ
		
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}	
}

//�ж��Ƿ�ƽ��
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
	//�ж��������Ƿ����
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
		{
			return board[i][2];
		}
	}
	//�ж��������Ƿ����
	for (i = 0; i < row; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ')
		{
			return board[2][i];
		}
	}
	//�ж�����б�Խ�
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != ' ')
	{
		return board[2][2];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[0][2] != ' ')
	{
		return board[0][2];
	}
	//���϶������㣬��Ҫô����Ҫôƽ��
	//�ж��Ƿ�ƽ��
	if (IsFull(board, ROW, COL) == 1)
	{
		return'Q';
	}
	return 'C';
}
