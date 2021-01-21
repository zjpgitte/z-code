#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

//前序
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	if (p == NULL && q == NULL)
	{
		return true;
	}

	//结构不同
	if (p && !q || q && !p)
	{
		return false;
	}

	//结构相同，值不同
	if (p->val != q->val)
	{
		return false;
	}

	//结构相同值也相同，向下判断
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
	
	
	
	system("pause");
	return 0;
}