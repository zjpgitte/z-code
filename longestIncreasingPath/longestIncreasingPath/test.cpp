#include <iostream>

using namespace std;



int direction[4][2] = { { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } };//记录方向。上下左右

int ROW, COL;

int Dfs(int **matrix, int row, int col, int **longestPath)
{
	if (longestPath[row][col] != 0)
	{
		return longestPath[row][col];
	}
	longestPath[row][col]++;

	//求从当前元素开始的最长路径
	for (int i = 0; i < 4; i++)
	{
		int newRow = row + direction[i][0], newCol = col + direction[i][1];//记录新元素的位置

		if (newRow >= 0 && newRow < ROW && newCol >= 0 && newCol < COL && matrix[newRow][newCol] > matrix[row][col])
		{
			int newPath = Dfs(matrix, newRow, newCol, longestPath) + 1;//记录新的路径

			//判断是否修改当前元素的最长路径
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

	ROW = matrixSize;//矩阵的行数
	COL = matrixColSize[0]; //矩阵的列数

	//创建二维数组记录原矩阵每个元素大的最长路径大小
	int **longestPath = (int**)malloc(sizeof(int*)*ROW);
	for (int i = 0; i < ROW; i++)
	{
		longestPath[i] = (int*)malloc(sizeof(int)* COL);
		memset(longestPath[i], 0, sizeof(int)*COL);
	}


	int maxPath = 0;//记录所有元素的最长路径

	//深度优先遍历求每个元素的最长路径，并保存在二维数组longestPath中
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			int curPath = Dfs(matrix, i, j, longestPath);//深度优先遍历求当前元素的最长路径

			//判断当前的最长路径是不是大于最大值
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