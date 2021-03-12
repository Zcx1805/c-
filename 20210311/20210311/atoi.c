#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
int MyAtoi(const char *arr){
	int sign = 1;
	long count = 0;
	if (arr == NULL){
		return 0;
	}
	while (*arr == ' '){
		arr++;
	}
	if (*arr == '-'){
		sign = -1;
		arr++;
	}
	while (*arr >= '0'&&*arr <= '9'&&*arr != '\0'){
		count = count * 10 + (*arr - '0');
		arr++;
	}
	return sign*count;
}

void test(){
	char* arr = "123";
	char* arr1 = "  123a";
	char* arr2 = "  123a123";
	char* arr3 = " -123";
	char* arr4 = "a123";
	printf("%d",MyAtoi(arr));
	printf("%d", atoi(arr));
	printf("\n");
	printf("%d", MyAtoi(arr1));
	printf("%d", atoi(arr1));
	printf("\n");
	printf("%d", MyAtoi(arr2));
	printf("%d", atoi(arr2));
	printf("\n");
	printf("%d", MyAtoi(arr3));
	printf("%d", atoi(arr3));
	printf("\n");
	printf("%d", MyAtoi(arr4));
	printf("%d", atoi(arr4));
	printf("\n");
}
int main(){
	test();
	system("pause");
	return 0;
}