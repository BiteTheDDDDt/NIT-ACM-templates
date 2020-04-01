#include<bits/stdc++.h>
using namespace std;
int i,i0,n,k;
char s[100005];
const int pr=769;
unsigned long long dic[100005],pre[100005];
unsigned long long get(int l,int r){return pre[r]-pre[l-1]*dic[r-l+1];}
map<unsigned long long,int>mp;
int main()
{
    scanf("%d %d %s",&n,&k,s+1);
    dic[0]=1;
    for(i=1;i<=n;i++)dic[i]=dic[i-1]*pr;
    for(i=1;i<=n;i++)pre[i]=pre[i-1]*pr+(s[i]-'a');
    for(i=1;i+k-1<=n;i++)mp[get(i,i+k-1)]++;
    int ans=0;
    for(auto i:mp)ans=max(ans,i.second);
    printf("%d\n",ans);
    return 0;
}