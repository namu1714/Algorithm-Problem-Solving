#include <iostream>

using namespace std;

long long a, b, c;

long long square(long long x){
	if(x == 1){
		return a % c;
	}
	if(x % 2 == 0)
		return (square(x/2) * square(x/2)) % c;
	else
		return (square(x/2) * square(x/2 + 1)) % c;
}

int main() {
	cin >> a >> b >> c;

	cout << square(b);
	
	return 0;
}