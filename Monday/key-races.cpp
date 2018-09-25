#include <iostream>
using namespace std;

int main(){
	int s;
	int v1;
	int v2;
	int t1;
	int t2;
	scanf ("%i %i %i %i %i",&s,&v1,&v2,&t1,&t2);
	
	long long int p1 = s*v1+2*t1;
	long long int p2 = s*v2+2*t2;
	
	//cout<<p1<<"\n";
	//cout<<p2<<"\n";
	if(p1<p2){
		cout<<"First\n";
	}
	
	else if(p2<p1){
		cout<<"Second\n";
	}
	else{
		cout<<"Friendship\n";
	}
	return 0;
}
