#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
//�������ݣ��ֲ������ĵ�ַ����������ֵ
char *GetMemery()
{
	char p[] = "hello world";//ջ�Ͽ��ٵ��ڴ�ռ䣬����������֮ǰռ�õ��ڴ�ȫ�����ͷţ�
	return p;				//�ڴ浱�е����ݱ�ΪʧЧ���ݣ����ɱ�����
							//�ڶ��庯��ʱӦ���⺯������ֵ��һ���ֲ������ĵ�ַ�����������������
}
void test()					//������test()��GetMemery()ʱ���Ⱥ󿪱������ڴ�ռ䣬�ֱ�����������ʹ��
{							//��GetMemery()���ý�����ԭ�ڴ�ռ䱻�ͷţ��������ݲ��䣬����ʱ��Ϊ��Ч
	char *str = NULL;		//���ٴε��ú���(����:printf())ʱ���Ḳ�ǵ�ԭGetMemery()ʹ�õ��ڴ棬�Ӷ��޸�
	str = GetMemery();		//���е����ݶ����� ��ӡ�� ���롣
	printf(str);	
}
int main()
{
	
	test();
	//int *p = NULL;
	//int *ptr = NULL;
	//ptr = (int *)malloc(0);
	//if (NULL == ptr)
	//{
	//	printf("malloc error!\n");
	//	return 1;
	//}
	//printf("malloc success!\n");
	//
	/*for (int i = 0; i < 6; i++)
	{
		*p = 4;
		printf("%d\n", *p);
		p++;
	}*/
	/*for (int i = 0; i < 20; i++)
	{
		*p = i;
		p++;
	}
	for (int i = 0; i < 20; i++)
	{
		printf("%d\n", *p);
	}*/
	/*char *ptr = (char*)realloc(p, 2);
	if (NULL == ptr)
	{
		printf("realloc error!\n");
		return 1;
	}
	p = ptr;*/
	//free(ptr);
	system("pause");
	return 0;
}