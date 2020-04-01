void Dirichlet(long long *a,long long *b)//a*b
{
    memset(tmp,0,sizeof tmp);
    for(int i=1;i*i<=n;++i)
    {
        tmp[i*i]+=a[i]*b[i]%mod, Mod(tmp[i*i]);
        for(int j=i+1;i*j<=n;++j)//下边加上a[i]*b[j]和a[j]*b[i]，所以j从i+1开始即可 
            (tmp[i*j]+=a[i]*b[j]%mod+a[j]*b[i]%mod)%=mod;//注意这加两个数不能一步用Mod取模。。
    }
    memcpy(a,tmp,sizeof tmp);
}