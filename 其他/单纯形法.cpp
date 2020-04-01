#include <bits/stdc++.h>
using namespace std;
const int maxn = 500; // 变量数目上限
const int maxm = 1500; // 约束数目上限
const double INF = 1e10;
const double eps = 1e-6;
struct Simplex
{
    int n;                // 变量个数
    int m;                // 约束个数
    double a[maxm+5][maxn+5]; // 输入矩阵
	double x[maxn+5];//方案
    int B[maxm+5], N[maxn+5]; // 算法辅助变量
	bool fn[maxn+5],fm[maxm+5];
    void pivot(int r, int c)
    {
        swap(N[c], B[r]);
        a[r][c] = 1 / a[r][c];
		if(fm[r])
		{
			fm[r]=0;
			for (int j = 0; j <= n; j++)
			{
				if (j != c) a[r][j] *= a[r][c];
				if(abs(a[r][j])>eps)fm[r]=1;
			}
			if(fn[c])
			{
				fn[c]=0;
				for (int i = 0; i <= m; i++)
				{
					if (i != r&&abs(a[i][c])>eps)
					{
						for (int j = 0; j <= n; j++)if (j != c) a[i][j] -= a[i][c] * a[r][j];
						a[i][c] = -a[i][c] * a[r][c];
					}
					if(abs(a[i][c])>eps)fn[c]=1;
				}
			}
		}
    }
    bool feasible()
    {
        while(1)
        {
            int r, c;
            double p = INF;
            for (int i = 0; i < m; i++)if (a[i][n] < p) p = a[r = i][n];
            if (p > -eps) return true;
            p = 0;
            for (int i = 0; i < n; i++)if (a[r][i] < p) p = a[r][c = i];
            if (p > -eps) return false;
            p = a[r][n] / a[r][c];
            for (int i = r + 1; i < m; i++)
			{
				if (a[i][c] > eps)
                {
                    double v = a[i][n] / a[i][c];
                    if (v < p) r = i, p = v;
                }
			}
            pivot(r, c);
        }
    }
    // 解有界返回1，无解返回0，无界返回-1。b[i]为x[i]的值，ret为目标函数的值
    int simplex()
    {
        for (int i = 0; i < n; i++) N[i] = i,fn[i]=1;
        for (int i = 0; i < m; i++) B[i] = n + i,fm[i]=1;
        if (!feasible()) return 0;
        while(1)
        {
            int r, c;
            double p = 0;
			for (int i = 0; i < n; i++)if (a[m][i] > p) p = a[m][c = i];
            if (p < eps)
            {
				//输出方案
                for (int i = 0; i < n; i++)if (N[i] < n) x[N[i]] = 0;
                for (int i = 0; i < m; i++)if (B[i] < n) x[B[i]] = a[i][n];
				//a[m][n]就是最大值 但是好像有精度误差
                return 1;
            }
            p = INF;
            for (int i = 0; i < m; i++)
                if (a[i][c] > eps)
                {
                    double v = a[i][n] / a[i][c];
                    if (v < p) r = i, p = v;
                }
            if (p == INF) return -1;
            pivot(r, c);
        }
    }
}sp;
double a[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%lf",&a[i]);
		int k,L,R;
		scanf("%d %d %d",&k,&L,&R);
		sp.n=n,sp.m=0;
		for(int i=0;i<n;i++)
		{
			for(int i0=0;i0<n;i0++)sp.a[sp.m][i0]=(i0==i);
			sp.a[sp.m++][n]=1;
		}
		for(int i=0;i+k-1<n;i++)
		{
			int l=i,r=i+k-1;
			for(int i0=0;i0<n;i0++)sp.a[sp.m][i0]=(i0>=l&&i0<=r);
			sp.a[sp.m++][n]=R;
			for(int i0=0;i0<n;i0++)sp.a[sp.m][i0]=-(i0>=l&&i0<=r);
			sp.a[sp.m++][n]=-L;
		}
		for(int i=0;i<n;i++)sp.a[sp.m][i]=a[i];
		sp.simplex();
		double ans=0;
		for(int i=0;i<n;i++)if(sp.x[i]>eps)ans+=a[i];
		printf("%.0f\n",ans);
		for(int i=0;i<n;i++)printf("%d",(sp.x[i]>eps));
		printf("\n");
	}
    return 0;
}