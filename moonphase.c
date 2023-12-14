#include <stdio.h>

int moon_phase(int year,int month,int day)
{
	int d, g, e;

	d = day;
	if(month == 2)
		d += 31;
	else if (month > 2)
		d += 59+(month-3)*30.6+0.5;
	g = (year-1900)%19;
	e = (11*g + 29) % 30;
	if(e == 25 || e == 24)
		++e;
	return ((((e + d)*6+5)%177)/22 & 7);
}


const char* moon_phase_name(int phase) {
	const char* phases[] = {
		"New Moon",
		"Waxing Crescent",
		"First Quarter",
		"Waxing Gibbous",
		"Full Moon",
		"Waning Gibbous",
		"Last Quarter",
		"Waning Crescent"
	};


	return phases[phase];
}

int main() {
	int year = 2023;  // Change the year
	int month = 12;   // Change the month
	int day = 25;  	  // Change the day

		printf("Please enter year:");
		scanf("%d", &year);
		printf("Please enter month:");
		scanf("%d", &month);
		printf("Please enter day:");
		scanf("%d", &day);


	int phase = moon_phase(year, month, day);
	const char* phase_name = moon_phase_name(phase);

	printf("The moon phase on %d-%02d-%02d is: %s\n", year, month, day, phase_name);

	return 0;
}




