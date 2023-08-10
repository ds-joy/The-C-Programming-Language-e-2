#include <stdio.h>

static char daytab[2][13] = {
		{0, 31, 28, 31,30, 31, 30, 31, 31, 30, 31, 30, 31},
		{0, 31, 28, 31,30, 31, 30, 31, 31, 30, 31, 30, 31}
};
void month_day(int year, int yearday, int *pmonth, int *pday);
int day_of_year(int year, int month, int day);


int main()
{
	int year, day, month, yearday;

	printf("Please enter year: ");
	scanf("%d", &year);
	
	printf("Please enter yearday: ");
	scanf("%d", &yearday);

	month_day(year, yearday, &month, &day);
	printf("Month: %d Day: %d\n", month, day);

	printf("Please enter year: ");
	scanf("%d", &year);
	
	printf("Please enter month: ");
	scanf("%d", &month);

	printf("Please enter day: ");
	scanf("%d", &day);

	printf("Year day: %d\n", day_of_year(year, month, day));
			   
	return 0;
}


/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int i, leap;
	if(year < 0) {
		printf("invalid year!\n");
		return -1;
	}
	leap = year % 4 == 0 && year%100 !=0 || year%400 == 0;
	if( (month >=1 && month <=12) && day >= 1 && ( day <= daytab[leap][month] ))
		for(i = 1; i < month; i++)
			day += daytab[leap][i];
	else {
		printf("invalid input!\n");
		return -1;
	} 
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for(i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}














































