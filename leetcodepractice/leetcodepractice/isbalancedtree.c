/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

//����

bool _isBalanced(struct TreeNode *root, int *height)
{
	//������ƽ�������
	if (root == NULL)
	{
		*height = 0;
		return true;
	}

	//�ж��������Ƿ���ƽ�������
	int leftHeight = 0;
	if (_isBalanced(root->left, &leftHeight) == false)
	{
		return false;
	}

	//��������ƽ��������ˣ����ж��������Ƿ���ƽ�������
	int rightHeight = 0;
	if (_isBalanced(root->right, &rightHeight) == false)
	{
		return false;
	}

	//������������ƽ���������
	//����жϵ�ǰ�����Ƿ���ƽ�������
	if (abs(leftHeight - rightHeight) > 1)
	{
		return false;
	}

	//��ǰ����ƽ�������������ǰ�߶ȴ���
	else
	{
		*height = leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
		return true;
	}

}

bool isBalanced(struct TreeNode* root){

	int height = 0;
	return _isBalanced(root, &height);
}