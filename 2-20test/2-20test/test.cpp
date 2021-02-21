#include "test.h"


char *TransformToChars(int x)
{
	int xcopy = x;
	int n = 0;//λ��
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
		int behind = cur; //behindָ����һ������ͬ���ַ���
		while (behind < charsSize && chars[behind] == chars[cur])
		{
			behind++;
		}
		int count = behind - cur; //��ǰ�ַ�����
		if (count > 1)
		{
			//��countת�����ַ�����ʽ
			char *countC = TransformToChars(count);
			//�����ַ������ǰ�ַ��ĺ���
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
			//��behind������β���ַ�����cur��
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