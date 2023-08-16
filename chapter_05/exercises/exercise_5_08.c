#include <stdio.h>

/* stores the day of the month */
static char daytab[2][13] = {
	{0, 31, 28, 31,30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31,30, 31, 30, 31, 31, 30, 31, 30, 31}
};


int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);


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


int day_of_year(int year, int month, int day)
{
	int i, leap;

	/* year error check */
	if(year < 0){
		printf("Invalid year!\n");
		return -1;
	}
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	/* month error check */
	if(month < 1 || month > 12) {
		printf("Invalid month!\n");
		return -1;
	}
	
	/* day error check */
	else if( day < 1 || day > daytab[leap][month]) {
		printf("Invalid day!\n");
		return -1;
	}
	else {
		for(i = 1; i < month; i++)
		day += daytab[leap][i];
	}
	return day;
}


void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	/* year error check */
	if(year < 0){
		printf("Invalid year!\n");
		return -1;
	}
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	if(yearday < 1 || (leap && yearday > 366) || (!leap && yearday > 365)) {
		printf("invalid yearday! \n");
		*pmonth = -1;
		*pday = -1;
	}
	else {
		for(i = 1; yearday > daytab[leap][i]; i++)
			yearday -= daytab[leap][i];
		*pmonth = i;
		*pday = yearday;
	}

}
































