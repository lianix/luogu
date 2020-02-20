#include <bits/stdc++.h>
using namespace std;

int matrix[32][32];

int dir[4][2]= {
{0, 1},
{1, 0},
{-1, 0},
{0, -1}
};

int  n;

struct Point {
	int x;
	int y;
};

queue<Point *> pq;

void handle(int i, int j)
{
	matrix[i][j] = 3;
	
	int k, newi, newj;
	
	for( k = 0; k < 4; k++) {
		newi = i + dir[k][0];
		newj = j + dir[k][1];
		
		if(newi < 0 || newi > n)
			continue;
		if(newj < 0 || newj > n)
			continue;

		if(matrix[newi][newj] == 0) {
			Point *p = new Point;
			p->x = newi;
			p->y = newj;
			pq.push(p);
		}
	}	
}

void bfs(int i, int j)
{
	if(matrix[i][j] != 0)
		return;
		
	handle(i, j);

	while(!pq.empty()) {
		Point *p = pq.front();
		pq.pop();
		handle(p->x, p->y);
		delete p;		
	}	
}

int main()
{
	scanf("%d", &n);
	
	int i, j;
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	//±ß½ç±éÀú 
	for(i = 0; i < n; i++) {
		bfs(0, i);
		bfs(i, 0);
		bfs(n - 1, i);
		bfs(i, n - 1);
	}
		
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(matrix[i][j] == 3)
				printf("0 ");
			else if(matrix[i][j] == 0)
				printf("2 ");
			else
				printf("1 ");
		}
		printf("\n");
	}

	return 0;
}
