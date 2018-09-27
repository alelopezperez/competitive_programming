#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int n;
char ch[300];
int main()
{
    while(cin>>n)
    {
        int a[5] = {0, 0, 0, 0, 0};
        for(int i = 0; i < n; i++)
        {
            cin>>ch[i];
            if(ch[i] == 'A')
                a[0]++;
            else if(ch[i] == 'G')
                a[1]++;
            else if(ch[i] == 'C')
                a[2]++;
            else if(ch[i] == 'T')
                a[3]++;
            else
                a[4]++;
        }
        int maxNum = n / 4;
        for(int i = 0; i < n; i++)
        {
            if(ch[i] == '?')
            {
                for(int j = 0; j < 4; j++)
                {
                    if(a[j] < maxNum)
                    {
                        if(j == 0)
                            ch[i] = 'A', a[0]++;
                        else if(j == 1)
                            ch[i] = 'G', a[1]++;
                        else if(j == 2)
                            ch[i] = 'C', a[2]++;
                        else if(j == 3)
                            ch[i] = 'T', a[3]++;
                        a[4]--;
                        break;
                    }
                }
            }
        }
        if(a[4] > 0 || a[0] > n / 4 || a[1] > n / 4 || a[2] > n / 4 || a[3] > n / 4)
            cout<<"==="<<endl;
        else
        {
            for(int i = 0; i < n; i++)
                cout<<ch[i];
            cout<<endl;
        }
    }
    return 0;
}

