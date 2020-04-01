void extgcd(long long a,long long b,long long& d,long long& x,long long& y)
{
    if(!b){d=a;x=1;y=0;}
    else{extgcd(b,a%b,d,y,x);y-=x*(a/b);}
}
long long inv(long long a,long long n)//要掰成正数来求
{
    if(a<0)a+=mod;
    long long d,x,y;
    extgcd(a,n,d,x,y);
    return d==1?(x+n)%n:-1;
}


inv[1]=1;
for(i=2;i<=7000;i++)inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;

static int mod_inv(int a, int m = MOD) {
    // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
    int g = m, r = a, x = 0, y = 1;

    while (r != 0) {
        int q = g / r;
        g %= r; swap(g, r);
        x -= q * y; swap(x, y);
    }

    return x < 0 ? x + m : x;
}