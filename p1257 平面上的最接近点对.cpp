#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100002;

struct Point {
    double x;
	double y;
};
Point p[MAXN];

int n;

bool cmp(Point &a1, Point &a2)
{
    if(a1.x == a2.x)
        return a1.y < a2.y;
    else
        return a1.x < a2.x;
}

bool cmpy(const int &a,const int &b)
{
    return p[a].y < p[b].y;
}

double dist(int i, int j)
{
    return sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
}

double mindist(int left, int right)
{
    double d = 0x4f4f4f4f;
    
    if(left == right)
		return d;

    if(left + 1 == right)
        return dist(left, right);
    
	int mid = (left + right) >> 1;
	
    double d1 = mindist(left, mid);
    double d2 = mindist(mid+1, right);
    
    d = min(d1, d2);
   
	int tmp[MAXN], idx = 0;
	for(int i = left; i <= right; i++) {
		if(fabs(p[i].x - p[mid].x) <= d)
			tmp[idx++] = i;
	}
	sort(tmp, tmp+idx, cmpy);
	
	for(int i = 0; i < idx; i++)
		for(int j = i+1; j < idx; j++) {
			if (p[tmp[j]].y - p[tmp[i]].y > d)
				break;
				
			d = min(d, dist(tmp[i], tmp[j])); 
		}
			
	return d; 
}

int main()
{
	scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
        scanf("%lf %lf", &p[i].x, &p[i].y);

    sort(p, p+n, cmp);
    
    printf("%.4lf\n", mindist(0, n-1));
    
    return 0;
}
