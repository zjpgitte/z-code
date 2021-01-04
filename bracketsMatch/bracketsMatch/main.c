
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>


bool isValid(char * s){
	Stack st;
	StackInit(&st);//��ʼ��ջ
	//����������ջ��ֻ��Ҫ�ж�ջ�������ź�s�еĵ�һ���������Ƿ�ƥ��
	//s��һ��ջ��Ƚ�һ�κ�������һ������֤sǰ������Ŷ���ջ���߶�
	//��ƥ�����
	while (*s != '\0')
	{
		if (*s == '(' || *s == '[' || *s == '{')//��������ջ
		{
			StackPush(&st, *s);
			s++;
		}
		else//�������ж�.(�жϺ�ջ���Ƿ�ƥ��)
		{
			if (StackEmpty(&st)) //ջ�ǿյĲ�ƥ��
			{
				return false;
			}
			else //ջ����Ԫ��
			{
				char top = StackTop(&st);
				if (top == '(' && *s == ')'
					|| top == '[' && *s == ']'
					|| top == '{' && *s == '}')//ջ���͵�ǰ������ƥ��
				{
					StackPop(&st);
					s++;
				}
				else//ջ���͵�ǰ�������Ų�ƥ��
				{
					return false;
				}
			}
		}
	}
	if (StackEmpty(&st))//s�ߵ����ջҲ��ɿգ�������ƥ��
	{
		return true;
	}
	else//s�ߵ�����ˣ�����ջû�ա�˵�������ŵ������������Ŷ಻ƥ��
	{
		return false;
	}
}