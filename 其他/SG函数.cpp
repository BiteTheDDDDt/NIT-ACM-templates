const int MN= 10000;
int data[MN],SG[MN],mid[MN];
void SG(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        memset(mid,0,sizeof(mid));
        for(j=1;data[j]<=i;j++)   mid[SG[i-data[j]]]=1;
        for(j=0;j<=n;j++)
            if(mid[j]==0)
            {
                SG[i]=j;
                break;
            }
    }
}

SJ定理
(1)游戏的SG函数不为0且游戏中某个单一游戏的SG函数大于 1; (2)游戏的SG函数为0且游戏中没有单一游戏的SG函数大于1。
