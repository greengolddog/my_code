#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, x, s;
    cin >> a >> b;
    x = a;
    a = max(a, b);
    b = min(b, x);
    while (a % b > 0) {
	x = b;
	s += a/b;
	b = a % b;
	a = x;
    }
    s += a/b;
    cout << s;
}
