#include <stdio.h>
#define ARR_MAX 50

int convert_fun(char*);

int main(void)
{
	int counter; 
	char working_str[ARR_MAX+1] = {0};

	printf("Please, enter your string (max 50 characters): \n");
	scanf("%s", working_str);

	counter = convert_fun(working_str);

	printf("result: \n%s\n", working_str);
	printf("no of changes: %d\n", counter);

	return 0;
}

int convert_fun(char* arr){
	int counter = 0;
	for(int i = 0; i < ARR_MAX+1; i++){
		if (arr[i] >= 97 && arr[i] <= 122){
			counter++;
			arr[i] = arr[i] - 32;
		} else if (arr[i] <= 90 && arr[i] >= 65){
			arr[i] = arr[i] + 32;
			counter++;
		}
	}
	return counter;
}