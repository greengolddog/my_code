#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a, s, n, aprosh;
    cin >> a;
    s = 0;
    n = 1;
    for (int i = 2; i <= a; i++) {
	while (a % i == 0) {
	    a = a / i;
	    s += 1;
	    if (s % 2 == 1) {
		n *= i;
	    }
	}
	s = 0;
    }
    cout << n;
}