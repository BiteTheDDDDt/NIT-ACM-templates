long long lcm(long long a,long long b){return a/__gcd(a,b)*b;}
int exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    int r=exgcd(b,a%b,x,y),t=x;
    x=y,y=t-a/b*y;
    return r;
}
