/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
//比较p的左树和q的右树是否相同
bool _isSymmetric(struct TreeNode *p, struct TreeNode *q)
{
	if (p == NULL && q == NULL)
	{
		return true;
	}

	if (p && !q || q && !p)
	{
		return false;
	}

	if (p->val != q->val)
	{
		return false;
	}
	//保证p,q均存在
	return _isSymmetric(p->left, q->right) && _isSymmetric(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root){
	if (root == NULL)
	{
		return true;
	}

	//比较root的左右子树是否对称
	return _isSymmetric(root->left, root->right);

}