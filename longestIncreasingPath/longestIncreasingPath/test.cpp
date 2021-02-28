#include <iostream>

using namespace std;



int direction[4][2] = { { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } };//��¼������������

int ROW, COL;

int Dfs(int **matrix, int row, int col, int **longestPath)
{
	if (longestPath[row][col] != 0)
	{
		return longestPath[row][col];
	}
	longestPath[row][col]++;

	//��ӵ�ǰԪ�ؿ�ʼ���·��
	for (int i = 0; i < 4; i++)
	{
		int newRow = row + direction[i][0], newCol = col + direction[i][1];//��¼��Ԫ�ص�λ��

		if (newRow >= 0 && newRow < ROW && newCol >= 0 && newCol < COL && matrix[newRow][newCol] > matrix[row][col])
		{
			int newPath = Dfs(matrix, newRow, newCol, longestPath) + 1;//��¼�µ�·��

			//�ж��Ƿ��޸ĵ�ǰԪ�ص��·��
			if (newPath > longestPath[row][col])
			{
				longestPath[row][col] = newPath;
			}
		}
	}

	return longestPath[row][col];
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize){
	if (matrixSize == 0)
	{
		return 0;
	}

	ROW = matrixSize;//���������
	COL = matrixColSize[0]; //���������

	//������ά�����¼ԭ����ÿ��Ԫ�ش���·����С
	int **longestPath = (int**)malloc(sizeof(int*)*ROW);
	for (int i = 0; i < ROW; i++)
	{
		longestPath[i] = (int*)malloc(sizeof(int)* COL);
		memset(longestPath[i], 0, sizeof(int)*COL);
	}


	int maxPath = 0;//��¼����Ԫ�ص��·��

	//������ȱ�����ÿ��Ԫ�ص��·�����������ڶ�ά����longestPath��
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			int curPath = Dfs(matrix, i, j, longestPath);//������ȱ�����ǰԪ�ص��·��

			//�жϵ�ǰ���·���ǲ��Ǵ������ֵ
			if (curPath > maxPath)
			{
				maxPath = curPath;
			}
		}
	}

	return maxPath;

}

int main()
{
	int b[3][3] = { { 7,7,5 }, { 2,4,6 }, { 8, 2, 0 } };
	int **a = (int**)malloc(sizeof(int*)* 3);
	for (int i = 0; i < 3; i++)
	{
		a[i] = (int*)malloc(sizeof(int)* 3);
		memcpy(a[i], b[i], sizeof(int)* 3);
	}
	

	int aSize[3] = { 0 };
	for (int i = 0; i < 3; i++)
	{
		aSize[i] = 3;
	}

	int ret = longestIncreasingPath(a, 3, aSize);

	system("pause");
	return 0;
}