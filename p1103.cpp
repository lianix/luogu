#include <bits/stdc++.h>
using namespace std;

struct Book{
    int h;
	int w;
};
Book b[105];

int n, m, k, minn = 1e8;
int f[105][105];

bool cmp(Book &b1, Book &b2)
{
    return b1.h < b2.h;
}

int main()
{
	int i, j, x;
	
	scanf("%d %d", &n, &k);
	
	for(i = 0; i < n; i++)
		scanf("%d %d", &b[i].h, &b[i].w);

	sort(b, b + n, cmp);
	
	memset(f, 0x7f, sizeof(f));
	for(i = 0; i < n; i++)
        f[i][1] = 0;

	for(i = 1; i < n; i++)
		for(j = 2; j <= min(i + 1, n - k); j++)
			for(x = 0; x <= i - 1; x++) {
				f[i][j]=min(f[i][j], f[x][j-1] + abs(b[i].w-b[x].w));
			}

	for(i = 0; i < n; i++) {
		minn=min(minn,f[i][n-k]);
	}
	
	printf("%d", minn);
	
	return 0;
}
