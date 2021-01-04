
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>


bool isValid(char * s){
	Stack st;
	StackInit(&st);//初始化栈
	//将左括号入栈，只需要判断栈顶的括号和s中的第一个右括号是否匹配
	//s入一次栈或比较一次后就向后走一步。保证s前面的括号都入栈或者都
	//已匹配过了
	while (*s != '\0')
	{
		if (*s == '(' || *s == '[' || *s == '{')//左括号入栈
		{
			StackPush(&st, *s);
			s++;
		}
		else//右括号判断.(判断和栈顶是否匹配)
		{
			if (StackEmpty(&st)) //栈是空的不匹配
			{
				return false;
			}
			else //栈中有元素
			{
				char top = StackTop(&st);
				if (top == '(' && *s == ')'
					|| top == '[' && *s == ']'
					|| top == '{' && *s == '}')//栈顶和当前右括号匹配
				{
					StackPop(&st);
					s++;
				}
				else//栈顶和当前的右括号不匹配
				{
					return false;
				}
			}
		}
	}
	if (StackEmpty(&st))//s走到最后栈也变成空，则括号匹配
	{
		return true;
	}
	else//s走到最后了，但是栈没空。说明左括号的数量比右括号多不匹配
	{
		return false;
	}
}