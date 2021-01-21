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

	//p,q只有一个结点存在(结构不同)
	if (p && !q || q && !p)
	{
		return false;
	}

	//p,q均存在，但值不相同
	if (p->val != q->val)
	{
		return false;
	}

	//p,q两结点相同,判断p,q的子树是否相同,都相同返回true，有一个不相同返回false
	return isSametree(p->left, q->left) && isSametree(p->right, q->right);

}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
	if (s == NULL)
	{
		return false;
	}

	//判断t和s是否相等
	if (isSametree(s, t))
	{
		return true;
	}

	//判断s的子树有没有和t相等的，有返回true，没有返回false
	return isSubtree(s->left, t) || isSubtree(s->right, t);
}