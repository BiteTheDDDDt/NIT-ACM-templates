在i位置可以判断0~i-1的循环：
如果i%(i-next[i])==0 那么就有循环
循环次数为 i/(i-next[i])
循环长度为 i-next[i]
        cal_nex(s,n);
        for(int i=0;i<n;i++)if((i+1)%(i-nex[i])==0&&nex[i]!=-1)printf("%d %d\n",i+1,(i+1)/(i-nex[i]));
        printf("\n");