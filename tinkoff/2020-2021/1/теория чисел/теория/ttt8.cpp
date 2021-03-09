#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a, b, x, aa, bb;
    cin >> a >> b;
    x = a;
    aa = a;
    bb = b;
    a = max(a, b);
    b = min(b, x);
    while (a % b > 0) {
	x = b;
	b = a % b;
	a = x;
    }
    cout << aa*bb/b;
}
