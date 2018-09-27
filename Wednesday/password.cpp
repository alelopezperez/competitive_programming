#include <iostream>

using namespace std;
#define MAXN 1000005

int pi[MAXN];
void kmpPreprocess(string &P) {
    int i = 0, j = -1, m = P.size();
    pi[0] = -1;
    while(i < m) {
        while(j>=0 and P[i] != P[j])
            j = pi[j];
            i ++, j++;
            pi[i] = j;
    }
}

int main() {
    string s;
    cin>>s;
    kmpPreprocess(s);
    int ans = pi[s.size()];
    bool found = 0;
    while(ans>0) {
        for(int i=s.size()-1; i>ans and not found; i--)
            found = pi[i]>=ans;
        if(found)
            break;
        ans = pi[ans];
    }
    if(found)
        cout<<s.substr(0, ans);
    else
        cout<<"Just a legend";
    cout<<endl;
}
