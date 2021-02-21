#include "test.h"


char *TransformToChars(int x)
{
	int xcopy = x;
	int n = 0;//位数
	while (xcopy)
	{
		xcopy /= 10;
		n++;
	}
	char *s = (char*)malloc(n + 1);
	s[n] = '\0';
	for (int i = n - 1; i >= 0; --i)
	{
		s[i] = x % 10 + '0';
		x /= 10;
	}
	return s;
}

int compress(char* chars, int charsSize){
	if (charsSize == 0)
	{
		return 0;
	}

	int cur = 0;
	while (cur < charsSize)
	{
		int behind = cur; //behind指向下一个不相同的字符处
		while (behind < charsSize && chars[behind] == chars[cur])
		{
			behind++;
		}
		int count = behind - cur; //当前字符个数
		if (count > 1)
		{
			//将count转换成字符串形式
			char *countC = TransformToChars(count);
			//将该字符串填到当前字符的后面
			char *pc = countC;
			while (*pc != '\0')
			{
				chars[++cur] = *pc;
				pc++;
			}
			if (behind >= charsSize)
			{
				return cur + 1;
			}
			if (cur + 1 == behind)
			{
				free(countC);
				continue;
			}
			//将behind处到结尾的字符拷到cur处
			int curI = cur;
			for (int i = behind; i < charsSize; i++)
			{
				chars[++curI] = chars[i];
			}
			charsSize -= behind - cur - 1;
			free(countC);
			cur++;
		}
		else
		{
			cur++;
		}
	}

	return cur;
}