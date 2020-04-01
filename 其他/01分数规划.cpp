#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mem(a, b) memset(a, b, sizeof(a))
#define INF 0X3f3f3f3f
const ll MAXN = 5000 + 7;
const ll MOD = 1e9 + 7;
//-------------------------------------------//
int n, m;
struct pop
{
    int a, b;
    double v;
    bool operator<(const pop &a) const
    {
        return a.v > v;//a.v越小越好，所以从大到小排序
    }
} num[MAXN];
double check(double ans)
{
    double va = 0, vb = 0;
    for (int i = 1; i <= n; i++)
    {
        num[i].v = num[i].a - num[i].b * ans;//num[i].v是偏移量。
    }
    sort(num + 1, num + 1 + n);
    for (int i = m + 1; i <= n;i++)
    {
        va+= num[i].a;
        vb += num[i].b;
    }
    return va / vb;
}
int main()
{
    while (scanf("%d %d", &n, &m) != EOF && n && m)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &num[i].a);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &num[i].b);
        }
        double temp = 0, ans = 1;
        while (fabs(temp - ans) > 1e-4)//精度
        {
            ans = temp;
            temp = check(temp);
        }
        printf("%.0lf\n", ans*100);
    }
}
