
#include <iostream>
using namespace std;
void weird(long long int a, long long int b){

	if(a == 0 || b == 0){
		cout<<a<<" "<<b<<"\n";
		exit(0);
	}

	if(a >= (2*b)){
		a %= 2*b;
		weird(a,b);		
		
	}


	else if(b >= (2*a)){
		b %= 2*a;
		weird(a,b);	
	}
	
	cout<<a<<" "<<b<<"\n";
	exit(0);
}

int main(){
	long long int a;
	long long int b;
	scanf ("%I64d %I64d",&a,&b);
	weird(a,b);
	
	return 0;

}
