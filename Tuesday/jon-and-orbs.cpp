#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <stdio.h>

using namespace std;
typedef long long ll;
const int N=10515;
double dp[N][1005];


int main()
{
    int q,k;
    while(~scanf("%d %d",&k,&q))
    {
        dp[0][0]=1;
        for(int i=1;i<=10005;i++)
        {
            dp[i][0]=0;
            for(int j=1;j<=k;j++)
            {
                dp[i][j]= dp[i-1][j-1]*((k-j+1)/(k*1.0)) + dp[i-1][j]*((j*1.0)/(k*1.0));
            }
        }
        while(q--)
        {
            int x;
            scanf("%d",&x);
           // printf("%d\n",ans[x]);
           for(int i=1;i<=N;i++)
           {
               if(dp[i][k]> (double)(x/(2000.0)) )
               {
                   printf("%d\n",i);
                   break;
               }
           }
        }
    }
    return 0;
}
