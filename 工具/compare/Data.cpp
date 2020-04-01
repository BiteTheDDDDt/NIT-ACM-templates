#include<bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());//Ë??ú?ý
long long rd(long long l,long long r)
{
    unsigned long long ans=rng();
    return (ans%(r-l+1))+l;
}
int main()
{
    int T=1;
    //printf("%d\n",T);
    while(T--)
    {
        int n=rd(1,10000);
        printf("%d\n",n);
    }
    return 0;
}
