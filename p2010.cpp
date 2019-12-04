#include <bits/stdc++.h>
using namespace std;

int year, month, day;
int date1, date2, date;
int year1, year2;
int cnt;

int md[13] = {0,
 31, 28, 31, 30, 31, 30,
 31, 31, 30, 31, 30, 31};

bool isrui(int year) 
{
	if(year % 400 == 0)
		return true;
		
	if(year%4 == 0) {
		if(year % 100 == 0)
			return false;
		else
			return true;
	}
	
	return false;
}

int main()
{
	scanf("%d %d", &date1, &date2);
	
	year1 = date1 / 10000;
	year2 = date2 / 10000;
	
	for(year = year1; year <= year2; year++) {
		if(isrui(year))
			md[2] = 29;
		else
			md[2] = 28;
			
		day = ((year / 100) % 10 ) * 10;
		day += year /1000;
		month = (year % 10) * 10;
		month += (year / 10) % 10;
		
		if(month > 12 || month < 1)
			continue;
		
		if(day < 1 || day > md[month])
			continue;
			
		date = year * 10000 + month * 100 + day;
		if(date >= date1 && date <= date2)
			cnt++;
	}
	
	printf("%d", cnt);
	return 0;
}
