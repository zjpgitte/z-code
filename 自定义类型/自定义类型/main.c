#include "mail.h"
//实现一个通讯录；
//通讯录可以用来存储1000个人的信息，每个人的信息包括：姓名、性别、年龄、电话、住址
//提供方法：
//添加联系人信息
//删除指定联系人信息
//查找指定联系人信息
//修改指定联系人信息
//显示所有联系人信息
//清空所有联系人
//以名字排序所有联系人
int main()
{
	contact person[MAXSIZE];
	int select = 0;
	int quit = 0;
	
	while (!quit)
	{
		Disaply(person);
		Menu();
		printf("操作#");
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