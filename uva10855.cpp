#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define debug(fmt, ...)
#endif

char a[200][200], b[200][200], c[200][200];
int na, nb;

void rote()
{
    int i, j;
    for (i = 0; i < nb; i++)
        for (j = 0; j < nb; j++)
        {
            c[i][j] = b[i][j];
        }
	debug("\nrote 90\n");
    for (i = 0; i < nb; i++) {
        for (j = 0; j < nb; j++)
        {
            b[i][j] = c[nb-j-1][i];
            debug("%c", b[i][j]);
        }
        debug("\n");
    }

}

void findb()
{
    int i, j, bi, bj, cnt = 0;
    bool flag;
    for (i = 0; i <= na-nb; i++)
        for (j = 0; j <= na-nb; j++)
        {
            flag = true;
            for(bi = 0; bi < nb; bi++) {
                for(bj = 0; bj < nb; bj++)
                    if (a[i+bi][j+bj] != b[bi][bj]) {
                        flag = false;
                        break;
                    }
                if(flag == false)
                    break;
            }
            if(flag == true)
            	cnt++;
        }
    
    printf("%d", cnt);       
}

int main()
{
    int i;
    while(1) 
    {
        scanf("%d %d", &na, &nb);
        if(na == 0)
            break;

        for(i=0; i < na; i++)
            scanf("%s", a[i]);

        for(i=0; i < nb; i++)
            scanf("%s", b[i]);
            
        findb();
        printf(" ");
        rote();
        findb();
        printf(" ");
        rote();
        findb();
        printf(" ");
        rote();
        findb();
        printf("\n");
    }
   
    return 0;
}
