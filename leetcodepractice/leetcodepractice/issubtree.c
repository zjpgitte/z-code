/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

bool isSametree(struct TreeNode *p, struct TreeNode *q)
{
	if (p == NULL && q == NULL)
	{
		return true;
	}

	//p,qֻ��һ��������(�ṹ��ͬ)
	if (p && !q || q && !p)
	{
		return false;
	}

	//p,q�����ڣ���ֵ����ͬ
	if (p->val != q->val)
	{
		return false;
	}

	//p,q�������ͬ,�ж�p,q�������Ƿ���ͬ,����ͬ����true����һ������ͬ����false
	return isSametree(p->left, q->left) && isSametree(p->right, q->right);

}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
	if (s == NULL)
	{
		return false;
	}

	//�ж�t��s�Ƿ����
	if (isSametree(s, t))
	{
		return true;
	}

	//�ж�s��������û�к�t��ȵģ��з���true��û�з���false
	return isSubtree(s->left, t) || isSubtree(s->right, t);
}