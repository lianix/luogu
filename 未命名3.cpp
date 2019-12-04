#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10;
int n = 5; //�� n ����
int rcd[MAX_N]; //��¼ÿ��λ�������
int used[MAX_N]; //������Ƿ��ù�
int num[MAX_N] = {2,3,4,5,6}; //�������� n ����

void full_permutation(int l) {
    int i;
    if (l == n){
        for (i=0; i<n; i++){
            printf("%d", rcd[i]);
            if (i < n-1) printf(" ");
        }
        printf("\n"); return ;
    }
    for (i=0; i<n; i++) //ö�����е���(n ��), ѭ���ӿ�ʼ
        if (!used[i]){ //�� num[i]û��ʹ�ù�, ����Ϊ��ʹ��
            used[i] = 1; 
            rcd[l] = num[i];//�� l λ�÷��ϸ���
            full_permutation(l+1); //����һ��λ��
            used[i] = 0; //����
        }
}

int main()
{
	full_permutation(0);
 } 
