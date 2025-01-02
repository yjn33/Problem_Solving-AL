#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int how_old(int age);


int main(void)
{
	printf("%d \n", how_old(24));
	
	return 0;


}




int how_old(int age)
{

	time_t time_raw = time(NULL);
	struct tm *time_info = localtime(&time_raw);
	
	int year_curr = (time_info -> tm_year) + 1900;
	


	if( ( (age > 0) && (age <= 120) ) )
	{
		return year_curr - age;

	}
	
	else
	{
		printf("age error \n");
		return -999999;
	
	}

}








