
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
  
  	vector<int> v(n);
	for (int i = 0; i < v.size(); i++) {
		cin >> v[i];
	}
  
  
  	if (v[0] % 2 != 0 && v[v.size() - 1] % 2 != 0 && v.size() % 2 != 0) {
    		cout << "Yes\n";
  	} 

	else {
    		cout << "No\n";
  	}

  	return 0;
}
