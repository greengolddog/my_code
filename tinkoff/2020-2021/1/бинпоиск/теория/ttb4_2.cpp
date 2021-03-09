#include <bits/stdc++.h>
using namespace std;
int main() {
    long double c;
    cin >> c;
    long double l = 0;
    long double r = c;
    for (int i = 0; i < 10000; i++) {
	long double mid = (l + r) / 2;
	if ((sqrt(mid)+(mid * mid)) < c) {
	    l = mid;
	} else {
	    r = mid;
	}
    }
    cout << setprecision(20) << r;
}