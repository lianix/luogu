#include<bits/stdc++.h>
using namespace std;
char x[60],y[60];
int n;
int main()
{
	cin>>n>>x;
	for(int i=0;i<strlen(x);i++)
	{
		for(int j=0;j<n;j++)
		{
			y[i]=x[i]+1;
			if(y[i]==123)
			{
				y[i]='a';
			}
		}
	}
	
	for(int i=0;i<strlen(y);i++)
	{
		cout<<y[i];
	}
}

