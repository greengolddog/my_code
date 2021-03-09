#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    long double a, b, c, d;
    cin >> c;
    long double l = -1000;
    long double r = 1000;
    for (int i = 0; i < 1000; i++) {
	long double mid = (l + r) / 2;
	if (((a*mid*a*mid*a*mid)+(b*mid*b*mid)+(c*mid)+d) <= 0) {
	    l = mid;
	} else {
	    r = mid;
	}
    }
    cout << l;
}