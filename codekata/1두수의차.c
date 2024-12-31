#include <stdio.h>


int sub_two(int num1, int num2);



int main(void)
{
	printf("%d \n",sub_two(500,22));
	
	return 0;


}




int sub_two(int num1, int num2)
{

	if( ( (num1 >= -50000) && (num1 <= 50000) ) && ( (num2 >= -50000) && (num2 <= 50000) ) )
	{
		return num1 - num2;
	
	}
	
	else
	{
		printf("num error \n");
		return -999999;
	
	}

}








