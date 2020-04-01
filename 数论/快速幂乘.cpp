long long qpow(long long a,long long b,long long mod){long long r=1,t=a; while(b){if(b&1)r=(r*t)%mod;b>>=1;t=(t*t)%mod;}return r;}


long long qmul(long long x,long long y,long long mod){return (x*y-(long long)((long double)x/mod*y)*mod+mod)%mod;}
long long qpow(long long a,long long b,long long mod){long long r=1,t=a; while(b){if(b&1)r=qmul(r,t,mod);b>>=1;t=qmul(t,t,mod);}return r;}