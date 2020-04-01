#include <cstdio>
#include <cstring>
#include<algorithm>
using namespace std;
const int maxn = 1500;
int pos, Size[maxn], List[maxn], Next[maxn];
char s[2000000], c, data[maxn][maxn], cmd[20];
int New_Node(void)
{
    return List[pos++];
}

void Del_Node(int t)
{
    List[--pos] = t;
}

void Find(int& p, int& b)
{
    for (b = 0; b != -1 && p > Size[b]; b = Next[b])
    {
        p -= Size[b];
    }
}

void Fill_Block(int b, int n, char* str, int e)
{
    if (b == -1)
    {
        return;
    }
    Next[b] = e;
    Size[b] = n;
    memcpy(data[b], str, n);
}

void Split(int b, int p)
{
    if (b == -1 || p == Size[b])
    {
        return;
    }
    int t = New_Node();
    Fill_Block(t, Size[b]-p, data[b]+p, Next[b]);
    Next[b] = t;
    Size[b] = p;
}

void Maintain(int b)
{
    for (; b != -1; b = Next[b])
    {
        for (int t = Next[b]; t != -1 && Size[b]+Size[t] <= maxn; t = Next[b])
        {
            memcpy(data[b]+ Size[b], data[t], Size[t]);
            Size[b] += Size[t];
            Next[b] = Next[t];
            Del_Node(t);
        }
    }
}

void Insert(int p, int n, char* str)
{
    int b, t, i;
    Find(p, b);
    Split(b, p);
    for (i = 0; i+maxn <= n; i += maxn)
    {
        t = New_Node();
        Fill_Block(t, maxn, str+i, Next[b]);
        Next[b] = t;
        b = t;
    }
    if (n-i)
    {
        t = New_Node();
        Fill_Block(t, n-i, str+i, Next[b]);
        Next[b] = t;
    }
    Maintain(b);
}

void Erase(int p, int n)
{
    int b, e;
    Find(p, b);
    Split(b, p);
    for (e = Next[b]; e != -1 && n > Size[e]; e = Next[e])
    {
        n -= Size[e];
    }
    Split(e, n);
    e = Next[e];
    for (int t = Next[b]; t != e; t = Next[b])
    {
        Next[b] = Next[t];
        Del_Node(t);
    }
    Maintain(b);
}

void Copy(int p, int n, char* str)
{
    int b, t, i;
    Find(p, b);
    i = min(n, Size[b]-p);
    memcpy(str, data[b]+p, i);
    for (t = Next[b]; t != -1 && i+Size[t] <= n; i += Size[t], t = Next[t])
    {
        memcpy(str+i, data[t], Size[t]);
    }
    if (n-i && t != -1)
    {
        memcpy(str+i, data[t], n-i);
    }
}

void Init(void)
{
    for (int i = 1; i < maxn; ++i)
    {
        List[i] = i;
    }
    pos = 1;
    Next[0] = -1;
    Size[0] = 0;
}

int main()
{

    int t, cur = 0, n;
    Init();
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", cmd);
        if (cmd[0] == 'M')
        {
            scanf("%d", &cur);
        }
        else if (cmd[0] == 'I')
        {
            scanf("%d", &n);
            for (int i = 0; i < n;)
            {
                c = getchar();
                if (32 <= c && c <= 126)
                {
                    s[i++] = c;
                }
            }
            s[n] = '\0';
            Insert(cur, n, s);
        }
        else if (cmd[0] == 'D')
        {
            scanf("%d", &n);
            Erase(cur, n);
        }
        else if (cmd[0] == 'G')
        {
            scanf("%d", &n);
            Copy(cur, n, s);
            s[n] = '\0';
            printf("%s\n", s);
        }
        else if (cmd[0] == 'P')
        {
            --cur;
        }
        else
        {
            ++cur;
        }
    }
    return 0;
}

