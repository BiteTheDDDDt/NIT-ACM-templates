#include <cstdio>
const int MAXN = 100010;
typedef long long ll;
int n;
ll a[MAXN], b[MAXN], ans, M, x, y;
ll exgcd(ll a, ll b, ll &x, ll &y){
    if(!b){ x = 1; y = 0; return a; }
    ll d = exgcd(b, a % b, x, y);
    ll z = x; x = y; y = z - (a / b) * y;
    return d;
}
ll Slow_Mul(ll n, ll k, ll mod){
    ll ans = 0;
    while(k){
      if(k & 1) ans = (ans + n) % mod;
      k >>= 1;
      n = (n + n) % mod;
    }
    return ans;
}
//min x=a mod b
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
       scanf("%lld%lld", &b[i], &a[i]);
    ans = a[1];
    M = b[1];
    for(int i = 2; i <= n; ++i){
       ll B = ((a[i] - ans) % b[i] + b[i]) % b[i];
       ll GCD = exgcd(M, b[i], x, y);
       x = Slow_Mul(x, B / GCD, b[i]);
       ans += M * x;
       M *= b[i] / GCD;
       ans = (ans + M) % M;
    }
    printf("%lld\n", ans);
    return 0;
}