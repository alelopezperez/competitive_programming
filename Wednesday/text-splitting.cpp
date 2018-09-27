#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define maxn 111
char s[maxn];
int n,p,q,ans;
int main()
{
    while(~scanf("%d%d%d%s",&n,&p,&q,s))
    {
        ans=-1;
        for(int i=0;i<=n/p;i++)
        {   
            for(int j=0;j<=n/q;j++)
                if(i*p+j*q==n)
                {
                    ans=i+j;
                    printf("%d\n",ans);
                    for(int k=0;k<n;k++)
                    {
                        printf("%c",s[k]);
                        if(i&&k<i*p&&!((k+1)%p)||j&&k>=i*p&&!((k-i*p+1)%q))printf("\n");
                    }
                    break;
                }
            if(ans!=-1)break;
        }
        if(ans==-1)printf("-1\n");
    }
    return 0;
}
