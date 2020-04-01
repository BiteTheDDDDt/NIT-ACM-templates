#include<bits/stdc++.h>
  using namespace std;

#define Abigail inline void
typedef long long LL;

const int N=1<<20;

char s[N+9];
int n,x[N+9],ts;

void Lyndon_word(){
  int j,k;
  for (int i=1;i<=n;){
  	for (j=i,k=i+1;k<=n&&s[k]>=s[j];++k)      //一直循环直到串结束或情况3出现 
  	  s[k]>s[j]?j=i:++j;      //情况1与情况2 
  	for (;i<=j;i+=k-j)
  	  x[++ts]=i+k-j-1;      //记录右端点 
  }
}

Abigail into(){
  scanf("%s",s+1);
  n=strlen(s+1);
}

Abigail work(){
  Lyndon_word();
}

Abigail outo(){
  for (int i=1;i<=ts;++i)
    printf("%d ",x[i]);
}

int main(){
  into();
  work();
  outo();
  return 0;
}