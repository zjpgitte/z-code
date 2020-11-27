#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)
int main()
{
	FILE *fp;
	fp = fopen("test.txt", "w");
	if (NULL == fp)
	{
		printf("open error!\n");
		system("pause");
		return 1;
	}
	char str[50] = "hello world!";
	fseek(fp,0 , SEEK_SET);
	fputs(str, fp);
	printf("%d\n", ftell(fp));
	//int arr[5] = { 0};
	//fread(arr, sizeof(int), 5, fp);
	//printf("%d ", arr[0]);
	//fwrite(arr, sizeof(int), sizeof(arr) / sizeof(arr[0]), fp);
	/*int a = 0;
	int b = 0;
	fscanf(fp, "%d %d", &a, &b);
	printf("%d %d", a, b);*/
	//fprintf(fp, "a:%d b:%d\n", a, b);
	//char str[100] = "this is a apple";
	////fputs(str, fp);
	//fgets(str, 16, fp);
	//printf("%s", str);
	//char ch = 0;
	/*while ((ch = getchar()) != EOF)
	{
		fputc(ch, fp);
	}*/
	//while ((ch = fgetc(fp)) != EOF)
	//{
	//	//fputc(ch, fp);
	//	printf("%c", ch);
	//}
	fclose(fp);
	system("pause");
	return 0;
}