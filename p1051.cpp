#include <bits/stdc++.h>
using namespace std;

struct student {
	char name[28];
	int avg;
	int eva;
	char monitor;
	char west;
	int paper;
	
	int scholarship; 
};

student s[108];
int n, total, maxs;

int main()
{
	scanf("%d", &n);
	for(int i=0; i < n; i++) {
		scanf("%s %d %d %c %c %d",  //%s %d %d%*c%c%*c%c %d"
			 s[i].name, &s[i].avg, &s[i].eva, &s[i].monitor, &s[i].west, &s[i].paper);
		//printf("%s, %d, %d, %c, %c, %d\n", 
		//	s[i].name, s[i].avg, s[i].eva, s[i].monitor, s[i].west, s[i].paper);
			
		if(s[i].avg > 80 && s[i].paper >= 1)
			s[i].scholarship += 8000;
		if(s[i].avg > 85 && s[i].eva > 80)
			s[i].scholarship += 4000;
		if(s[i].avg > 90)
			s[i].scholarship += 2000;
		if(s[i].avg > 85 && s[i].west == 'Y')
			s[i].scholarship += 1000;
		if(s[i].eva > 80 && s[i].monitor == 'Y')
			s[i].scholarship += 850;
			
		total += s[i].scholarship;
		if(s[i].scholarship > s[maxs].scholarship)
			maxs = i;		
	}
	
	printf("%s\n%d\n%d\n", s[maxs].name, s[maxs].scholarship, total);
	return 0;

}
