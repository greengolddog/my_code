#include <bits/stdc++.h>
using namespace std;
int main() {
    long double c;
    cin >> c;
    long double l = 0;
    long double r = 3;
    for (int i = 0; i < 1000; i++) {
	long double mid = (l + r) / 2;
	if ((cos(mid)-(c*mid)) > 0) {
	    l = mid;
	} else {
	    r = mid;
	}
    }
    cout << setprecision(20) << r;
}