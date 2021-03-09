#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a, b, x, num;
    cin >> num >> b;
    for (int i = 1; i < num; i++) {
	cin >> a;
	x = a;
	a = max(a, b);
	b = min(b, x);
	while (a % b > 0) {
	    x = b;
	    b = a % b;
	    a = x;
	}
    }
    cout << b;
}
