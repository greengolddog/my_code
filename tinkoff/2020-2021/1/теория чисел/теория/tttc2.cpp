#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a;
    cin >> a;
    for (int i = 2; i*i <= a; i++) {
	if (a % i == 0) {
	    while (a % i == 0) {
		a = a / i;
		cout << i << ' ';
	    }
	}
    }
    if (a > 1) {
	cout << a;
    }
}
