#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <errno.h>
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
#pragma warning(disable:4996)
int main()
{
	char killer = 0;
	for (killer = 'A'; killer <= 'D'; killer++)
	{
		if (((killer != 'A') +( killer == 'C') + (killer == 'D') + (killer != 'D')) == 3)
		{
			printf("%c\n", killer);
			break;
		}
	}
	system("pause");
	return 0;
}