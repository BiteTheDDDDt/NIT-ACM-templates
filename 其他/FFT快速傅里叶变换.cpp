#include<bits/stdc++.h>
using namespace std;
const int N=1<<18;
struct E
{
	double a,b;
	E(double A=0,double B=0){a=A;b=B;}
	E operator + (E y){return E(a+y.a,b+y.b);}
    E operator - (E y){return E(a-y.a,b-y.b);}
    E operator * (E y){return E(a*y.a-b*y.b,a*y.b+b*y.a);}
}w[N],a[N];
void fft(E *a,int n,int tp)
{
    for(int i=1,j=0; i<n; i++)
    {
        for(int k=(n>>1);!((j^=k)&k); k>>=1);
        if(i<j)swap(a[i],a[j]);
    }
    for(int j=2;j<=n;j<<=1)
    {
        w[0]=1,w[1]=E(cos(2*acos(-1)/j),tp*sin(2*acos(-1)/j));
        int m=(j>>1)-1;
        for(int i=2;i<=m;i++)w[i]=w[i-1]*w[1];
        for(int i=0; i<n; i+=j)
        {
            for(int k=0;k<=m;k++)
            {
                E x=a[i+k+(j>>1)]*w[k];
                a[i+k+(j>>1)]=a[i+k]-x;
                a[i+k]=a[i+k]+x;
            }
        }
    }
}
int x,n,m,i;
int main()
{
	scanf("%d %d",&n,&m);
	for(i=0;i<=n;i++)scanf("%d",&x),a[i].a=x;
	for(i=0;i<=m;i++)scanf("%d",&x),a[i].b=x;
	int r=1;
    while(r<=n+m)r*=2;
	fft(a,r,1);
	for(i=0;i<=r;i++)a[i]=a[i]*a[i];
	fft(a,r,-1);
	for(i=0;i<=n+m;i++)printf("%d ",int(a[i].b/(r*2)+0.5));
	return 0;
}
