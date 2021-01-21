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

//ǰ��
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	if (p == NULL && q == NULL)
	{
		return true;
	}

	//�ṹ��ͬ
	if (p && !q || q && !p)
	{
		return false;
	}

	//�ṹ��ͬ��ֵ��ͬ
	if (p->val != q->val)
	{
		return false;
	}

	//�ṹ��ֵͬҲ��ͬ�������ж�
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
	
	
	
	system("pause");
	return 0;
}