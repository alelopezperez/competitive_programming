#include <cstdio>
using namespace std;

const int max = 10000000;
int n,ans;
int f[max];

int main(){
	scanf("%d",&n);
	ans = n;
	for (int i=2; i<=n; i++) {
        	if (!f[i]) {
            		for (int j=2*i; j<=n; j+=i) f[j] = i;
        	}
		f[i] = i-f[i]+1;
    	}

    	for (int i=f[n]; i<=n; i++){
		if( ans >= f[i]){
			ans = f[i];		
		}

	}

    	printf("%d\n",ans);
    	return 0;
}

