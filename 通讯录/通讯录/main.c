#include "main.h"

int main()
{
	contact_t *contact;
	InitContact(&contact);
	int quit = 0;
	int select = 0;
	while (!quit)
	{
		Menu();
		printf("«Î ‰»Î£∫");
		scanf("%d", &select);
		switch (select)
		{
		case 1:InsertPerson(&contact);
			break;
		case 2:DelPerson(contact);
			break;
		case 3:printf(" ‰»Î–’√˚:");
			char nam[SIZE / 4];
			scanf("%s", nam);
			SearchPerson(contact,nam);
			break;
		case 4:ModifyPerson(contact);
			break;
		case 5:Disaply(contact);
			break;
		case 6:ClearContact(contact);
			break;
		case 7:SortContact(contact);
			break;
		default:quit = 1;
			Save(contact);
			break;
		}
		system("pause");
		system("cls");
		
	}

	system("pause");
	return 0;
}
