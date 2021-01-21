/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

//后序

bool _isBalanced(struct TreeNode *root, int *height)
{
	//空树是平衡二叉树
	if (root == NULL)
	{
		*height = 0;
		return true;
	}

	//判断左子树是否是平衡二叉树
	int leftHeight = 0;
	if (_isBalanced(root->left, &leftHeight) == false)
	{
		return false;
	}

	//左子树是平衡二叉树了，再判断右子树是否是平衡二叉树
	int rightHeight = 0;
	if (_isBalanced(root->right, &rightHeight) == false)
	{
		return false;
	}

	//左右子树都是平衡二叉树，
	//最后判断当前的树是否是平衡二叉树
	if (abs(leftHeight - rightHeight) > 1)
	{
		return false;
	}

	//当前树是平衡二叉树，将当前高度带回
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