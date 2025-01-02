#include <stdio.h>


int div_two(int num1, int num2);



int main(void)
{
	printf("%d \n", div_two(10,5));
	
	return 0;


}




int div_two(int num1, int num2)
{

	if( ( (num1 >= 0) && (num1 <= 100) ) && ( (num2 >= 0) && (num2 <= 100) ) )
	{
		return num1 / num2;
	
	}
	
	else
	{
		printf("num error \n");
		return -999999;
	
	}

}








