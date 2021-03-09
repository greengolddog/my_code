#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a, s, d;
    cin >> a;
    s = 0;
    d = 0;
    for (int i = 2; i*i <= a; i++) {
	if (a % i == 0) {
	    if (d == 1) {
		cout << '*';
	    }
	    d = 1;
	    cout << i;
	    while (a % i == 0) {
		a = a / i;
		s += 1;
	    }
	    if (s > 1) {
		cout << '^' << s;
	    }
	    s = 0;
	}
    }
    if (a > 1) {
	if (d == 1) {
	    cout << '*';
	}
	cout << a;
    }
}
