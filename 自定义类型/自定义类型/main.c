#include "mail.h"
//ʵ��һ��ͨѶ¼��
//ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ�������������Ա����䡢�绰��סַ
//�ṩ������
//�����ϵ����Ϣ
//ɾ��ָ����ϵ����Ϣ
//����ָ����ϵ����Ϣ
//�޸�ָ����ϵ����Ϣ
//��ʾ������ϵ����Ϣ
//���������ϵ��
//����������������ϵ��
int main()
{
	contact person[MAXSIZE];
	int select = 0;
	int quit = 0;
	
	while (!quit)
	{
		Disaply(person);
		Menu();
		printf("����#");
		scanf("%d", &select);
		getchar();
		switch (select)
		{
		case 1:AddContact(person);
			break;
		case 2:DelectContact(person);
			break;
		case 3:SearchContact(person);
			break;
		case 4:ReverseContact(person);
			break;
		case 5:
			break;
		case 6:EmptyContact(person);
			break;
		case 7:NameSortContact(person);
			break;
		case 0:quit = 1;
			break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}