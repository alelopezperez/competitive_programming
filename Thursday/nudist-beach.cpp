#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(i, a, b)    for (int i(a); i <= (b); ++i)
#define dec(i, a, b)    for (int i(a); i >= (b); --i)
 
typedef long long LL;
 
const double eps = 1e-8;
 
const int N = 100010;
int n, m, k;
vector <int> v[N];
int deg[N], irr[N], b[N], c[N], g[N], inn[N], ans[N];
int cnt = 0;
 
 
bool check(double x){
 
    int num = cnt;
    queue <int> Q;
    rep(i, 1, cnt) g[c[i]] = 1;
    rep(i, 1, cnt) inn[c[i]] = deg[c[i]] - irr[c[i]];
    rep(i, 1, cnt){
        if ((double)(inn[c[i]]) / (double)deg[c[i]] < x){
            Q.push(c[i]);
            g[c[i]] = 0;
            --num;
        }
    }
 
    while (!Q.empty()){
        int now = Q.front(); Q.pop();
        for (auto u : v[now]) if (g[u]){
            --inn[u];
            if ((double)inn[u] / (double)deg[u] < x){
                Q.push(u);
                g[u] = 0;
                --num;
            }
        }
    }
     
    if (num){
        int et = 0;
        rep(i, 1, cnt) if (g[c[i]]) ans[++et] = c[i];
        ans[0] = num;
        return true;
    }
 
    else return false;
}  
 
int main(){
 
    scanf("%d%d%d", &n, &m, &k);
    rep(i, 1, k){
        int x;
        scanf("%d", &x);
        b[x] = 1;
    }
 
    rep(i, 1, m){
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
        ++deg[x], ++deg[y];
        if (b[x]) ++irr[y];
        if (b[y]) ++irr[x];
    }
 
    double l = 0.00, r = 1.00;
 
    cnt = 0;
    rep(i, 1, n) if (!b[i]) c[++cnt] = i;
         
 
    rep(i, 1, 100){
        double mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid - eps;
    }
 
    printf("%d\n", ans[0]);
    rep(i, 1, ans[0]) printf("%d ", ans[i]);
    putchar(10);
 
    return 0;
}
