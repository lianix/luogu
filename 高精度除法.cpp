#include <bits/stdc++.h>
using namespace std;

const int MAXN = 506;
int a[MAXN], b[MAXN], c[MAXN];
char ac[MAXN], bc[MAXN];

// ʹ��a[0] b[0] c[0] ��ʾ���� 

void convert(char ca[], int a[])
{
    int len = strlen(ca);
	for(int i = 1; i <= len; i++)
	{
		a[i] = ca[len - i] - '0';
	}
	a[0] = len;
}

void print(int ans[])
{
    for(int i = ans[0]; i >= 1; i--)
        printf("%d", ans[i]);
}


// 1 �������,  -1 ����С��, 0 �������.
int compare(int a[], int b[])
{
    int lena = a[0];
    int lenb = b[0];
    
    if(lena > lenb) return 1;
    if(lenb > lena) return -1;
    //�Ӹ�λ��ʼ�Ƚ� 
    for(int i = lena; i >=1; i--)
    {
        if(a[i] > b[i]) return 1;
        if(a[i] < b[i]) return -1;
    }
    
    return 0; //a==b
}
 
void sub(int a[],int b[])//����a=a-b
{
    int flag;
    int i;
 
    flag=compare(a,b);
    if(flag==0)//���
    {
        a[0]=0;
        return;
    }
    if(flag==1)//����
    {
        for(i=1;i<=a[0];i++)
        {
            if(a[i]<b[i])//���������Ͻ�λ
            {
                a[i+1]--;
                a[i]+=10;
            }
            a[i]-=b[i];
        }
        while(a[0]>0&&a[a[0]]==0)//ɾ��ǰ��0
            a[0]--;
        return;
    }
}
int main()
{
    cin>>ac>>bc;
    
	convert(ac, a);
	convert(bc, b);
 
    int temp[MAXN], i, j;
    
    c[0]=a[0]-b[0]+1;
    for(i = c[0]; i > 0; i--)
    {
        memset(temp,0,sizeof(temp));
        for(j = 1; j <= b[0]; j++)//��i��ʼ�ĵط�����������b������temp
            temp[j+i-1]=b[j];
        temp[0]=b[0]+i-1;
 
        while(compare(a,temp)>=0)//�ü���ģ��
        {
            c[i]++;
            sub(a,temp);
        }
    }
 
    while(c[0]>0 && c[c[0]]==0)//ɾ��ǰ��0
        c[0]--;
 
    cout<<"��Ϊ��";
    if(c[0]==0)//������
        cout<<0<<endl;
    else
    {
        for(i=c[0];i>0;i--)
            cout<<c[i];
        cout<<endl;
    }
 
    cout<<"����Ϊ��";
    if(a[0]==0)//�������
        cout<<0<<endl;
    else
    {
        for(i=a[0];i>0;i--)
            cout<<a[i];
        cout<<endl;
    }
 
    return 0;
}
