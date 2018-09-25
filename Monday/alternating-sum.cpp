
#include<iostream>
#define rep(i,l,r) for (int i=l;i<=r;i++)

typedef long long ll;
const ll mm=1e9+9;
using namespace std;
ll a,b,ans;
int n,k;
char s[100500];

ll Pow(ll x,ll y){
	ll ans=1;
	while (y){
		if (y&1) ans=ans*x%mm;
		x=x*x%mm;
		y/=2;
	}
	return ans;
}
int main(){
	scanf("%d%I64d%I64d%d",&n,&a,&b,&k);
	scanf("%s",s);
	b=b*Pow(a,mm-2)%mm;
	for(int i=k-1;i>=0;i--) ans=(ans*b+(s[i]=='+'?1:mm-1))%mm;
	b=Pow(b,k);
	int sz=(n+1)/k;

	if (b==1) 
		ans=ans*sz%mm;
	else 
		ans=ans*(Pow(b,sz)-1)%mm*Pow(b-1,mm-2)%mm;

	ans=ans*Pow(a,n)%mm;
	ans=(ans+mm)%mm;
	printf("%lld\n",ans);
	return 0;
}
