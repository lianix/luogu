#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10;
int n = 5; //共 n 个数
int rcd[MAX_N]; //记录每个位置填的数
int used[MAX_N]; //标记数是否用过
int num[MAX_N] = {2,3,4,5,6}; //存放输入的 n 个数

void full_permutation(int l) {
    int i;
    if (l == n){
        for (i=0; i<n; i++){
            printf("%d", rcd[i]);
            if (i < n-1) printf(" ");
        }
        printf("\n"); return ;
    }
    for (i=0; i<n; i++) //枚举所有的数(n 个), 循环从开始
        if (!used[i]){ //若 num[i]没有使用过, 则标记为已使用
            used[i] = 1; 
            rcd[l] = num[i];//在 l 位置放上该数
            full_permutation(l+1); //填下一个位置
            used[i] = 0; //清标记
        }
}

int main()
{
	full_permutation(0);
 } 
