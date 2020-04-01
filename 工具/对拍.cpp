#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s,t,s0,cnt=0;
    while(1)
    {
        system("cls");
        do
        {
            system("data.exe > data.txt"); //data是数据生成程序，自己写
            s=clock();
            system("TmpCode0.exe < data.txt > try0.out");  //a是要测试的程序
            t=clock();
            system("TmpCode1.exe < data.txt > try1.out");  //b是正确的程序
            s0=clock();
            printf("Test:%d\n",++cnt);
            if(system("fc try0.out try1.out > nul"))break;
            else printf("AC time0: %ldms time1:%ldms\n",t-s,s0-t); //并输出运行时间
        }while(1);
        printf("WA time0: %ldms time1:%ldms\n",t-s,s0-t);  //运行时间 wa了会停止对拍，wa的那一组会在data.txt里，所以说为了方便查找一次不要生成太大量的数据
        system("fc try0.out try1.out");
        system("pause>nul");
    }
    return 0;
}