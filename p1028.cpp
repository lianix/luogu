#include <cstdio>
#include <queue>
 
using namespace std;

#if 0   //µÝ¹é - TLE
int append(int n)
{
	int sum = 0;
	if (n == 1)
		return 1;
	else {
		for ( int i = 1; i <= n/2; i++)
			sum += append(i);
		return sum + 1;		
	}
}
#endif
 
#if 0 //¶ÓÁÐ  // memory limitation
int main()
{
	int a, b;
	int total = 0;
	queue<int> q;
	
	scanf("%d", &a);
	//total = append(a);
	for ( int i = 1; i <= a/2; i++)
		q.push(i);
		
	while(!q.empty()) {
		b = q.front();
		q.pop();
		total++;
		b /=2;
		
		if(b==1) {
			total++;
			continue;
		}
			
		if(b == 2 || b == 3) {	
			total +=2;
			continue;
		}
		
		for ( int i = 1; i <= b; i++)
			q.push(i);
	}

	printf("%d", total + 1);
	
	return 0;
}
#endif

//µÝÍÆ
int  a[1005] = {0,}; 
int main()
{
	int n;
		
	scanf("%d", &n);
	//total = append(a);
	a[0] = 0;
	a[1] = 1;
	
	for (int i = 2; i<=n; i++) {
			a[i] += 1;
			for(int j = 0; j <= i/2; j++) {	
				a[i] += a[j];
			}
	}

	printf("%d", a[n]);
	
	return 0;
}


