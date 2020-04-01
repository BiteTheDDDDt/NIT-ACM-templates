#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[10005],nex[10005],i,i0,n,m,T,ans,k;
void cal_nex(int *str,int len)
{
    nex[0]=-1;
    for (int q=1,k=-1;q<len;q++)
    {
        while(k!=-1&&str[k+1]!=str[q])k=nex[k];
        if (str[k+1]==str[q])k++;
        nex[q]=k;
    }
}
int KMP(int *str,int slen,int *ptr,int plen)
{
    cal_nex(ptr,plen);
    for(int i=0,k=-1;i<slen;i++)
    {
        while(k>-1&&ptr[k+1]!=str[i])k=nex[k];
        if(ptr[k+1]==str[i])k++;
        if(k==plen-1)return i-plen+2;
    }
    return -1;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        for(i=0;i<m;i++)scanf("%d",&b[i]);
        printf("%d\n",KMP(a,n,b,m));
    }
    return 0;
}
