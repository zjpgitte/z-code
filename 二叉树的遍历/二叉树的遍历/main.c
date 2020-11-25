#include <stdio.h>
#include <windows.h>
//������Ҫ�󡿴Ӽ�������һ�ö��������������У��Զ���������Ϊ�洢�ṹ��������������������б�������������ͺ��򣩣�
//Ȼ�󽫱��������ӡ�����Ҫ���д�ݹ�ͷǵݹ������㷨��ʵ�֡�
//���������ݡ� �������У�ABC**DE*G**F***������*��ʾ��������
//����������������ABCDEGF
//��������CBEGDFA
//��������CGEFDBA
typedef struct Tree
{
	char c;
	struct Tree *Lchild;
	struct Tree *Rchild;
}*bitree,bitreenode;
void InitBitree(bitree *root)
{
	*root =(bitree)malloc(sizeof(bitreenode));
	(*root)->Lchild = NULL;
	(*root)->Rchild = NULL;
}
void PreOrderInput(bitree *root)
{
	if (NULL == root)
	{
		return;
	}
	char ch;
	ch = getchar();
	if ('*' != ch)
	{
		*root = (bitree)malloc(sizeof(bitreenode));
		(*root)->Lchild = NULL;
		(*root)->Rchild = NULL;
		(*root)->c = ch;
		PreOrderInput(&((*root)->Lchild));
		PreOrderInput(&((*root)->Rchild));
	}
}
void PreOrderTravel(bitree root)
{
	if (NULL != root)
	{
		printf("%c", root->c);
		PreOrderTravel(root->Lchild);
		PreOrderTravel(root->Rchild);
	}
}
void InOrderTravel(bitree root)
{
	if (NULL != root)
	{
		InOrderTravel(root->Lchild);
		printf("%c", root->c);
		InOrderTravel(root->Rchild);
	}
}
void PostOrderTravel(bitree root)
{
	if (NULL != root)
	{
		PostOrderTravel(root->Lchild);
		PostOrderTravel(root->Rchild);
		printf("%c", root->c);
	}
}
int main()
{
	bitree root;
	//InitBitree(&root);
	printf("�������У�");
	PreOrderInput(&root);//��ʼ����������ÿ���ڵ�
	printf("�������У�");
	PreOrderTravel(root);
	printf("\n�������У�");
	InOrderTravel(root);
	printf("\n�������У�");
	PostOrderTravel(root);
	printf("\n");
	system("pause");
	return 0;
}