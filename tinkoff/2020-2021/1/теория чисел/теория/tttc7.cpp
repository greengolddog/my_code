
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a1, a2, b1, b2, x, a, b, aa, bb;
    cin >> a1 >> a2 >> b1 >> b2;
    a1 *= b2;
    b1 *= a2;
    a = a1+b1;
    b = a2*b2;
    aa = a;
    bb = b;
    x = a;
    a = max(a, b);
    b = min(b, x);
    while (a % b > 0) {
	x = b;
	b = a % b;
	a = x;
    }
    cout << aa/b << ' ' << bb/b;
}
