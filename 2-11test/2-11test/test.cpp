#include "test.h"

bool canConstruct(char * ransomNote, char * magazine){

	// char *str = (char*)malloc(strlen(magazine)+1);
	// strcpy(str,magazine);
	// char *pr = ransomNote;
	// char *ps = str;
	// while(*pr != '\0')
	// {
	//     ps = str;
	//     while(*ps != '\0' && *ps != *pr)
	//     {
	//        ps++;
	//     }

	//     //循环退出原因
	//     if(*ps == '\0')
	//     {
	//         return false;
	//     }
	//     else//(*ps == *pr)
	//     {
	//         *ps = '@';
	//         pr++;
	//     }

	// }
	// free(str);
	// return true;

	int count[26] = { 0 };
	char *pm = magazine;
	while (*pm != '\0')
	{
		count[*pm - 'a']++;
		pm++;
	}
	char *pr = ransomNote;
	while (*pr != '\0')
	{
		if (count[*pr - 'a'] <= 0)
		{
			return false;
		}
		else
		{
			count[*pr - 'a']--;
			pr++;
		}
	}
	return true;

}

bool isPalindrome(int x){
	if (x < 0)
	{
		return false;
	}
	int x_copy = x;

	//求x位数n
	int n = 0;
	while (x_copy)
	{
		x_copy /= 10;
		n++;
	}

	int *arr = malloc(sizeof(int)*n);

	//x的每一位放到数组中
	x_copy = x;
	int i = n;
	while (x_copy)
	{
		arr[--i] = x_copy % 10;
		x_copy /= 10;
	}

	int left = 0, right = n - 1;
	while (left < right)
	{
		if (arr[left] != arr[right])
		{
			return false;
		}
		else
		{
			left++;
			right--;
		}
	}
	return true;

	//if (x < 0 || x % 10 == 0 && x / 10 != 0)
	//{
	//	return false;
	//}

	//int number = 0;
	//while (x > number)
	//{
	//	number = number * 10 + x % 10;
	//	x /= 10;
	//}

	//return x == number || x == number / 10;
}