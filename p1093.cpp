#include <bits/stdc++.h>
using namespace std;

struct student {
	int id;
	int chinese;
	int math;
	int english;
	int total;
};

student s[7];
int n;

bool compare(student s1, student s2) 
{
	if(s1.total > s2.total)
		return true;
	if(s1.total < s2.total)
		return false;
	
	if(s1.chinese > s2.chinese)
		return true;
	if(s1.chinese < s2.chinese)
		return false;
		
	if(s1.id < s2.id)
		return true;
	else 
		return false;	
}

void insert(student s2)
{
	s[6] = s2;
	for(int i = 5; i > 0; i--)
	{
		if(compare(s[i + 1], s[i])) {
			student s3 = s[i];
			s[i] = s[i+1];
			s[i+1] = s3;
		} else
			break;
	}
}

int main()
{
	scanf("%d", &n);
	for(int i=1; i <= n; i++) {
		scanf("%d %d %d", &s[0].chinese, &s[0].math, &s[0].english);
		s[0].total = s[0].chinese + s[0].math + s[0].english;
		s[0].id = i;
		
		insert(s[0]);	
	}
	
	for(int i = 1; i <=5; i++) {
		printf("%d %d\n", s[i].id, s[i].total);
	}
	
	return 0;
}
