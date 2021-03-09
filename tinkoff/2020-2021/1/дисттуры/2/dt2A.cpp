#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, p, o, dp, op, nz;
    cin >> n >> p >> o;
    dp = floor(p / o);
    op = p % o;
    nz = 0;
    if (dp >= 1) {
	while (floor(n / p) > 0) {
	    nz += (floor(n / p) * dp);
	    n = n % p + (floor(n / p) * op);
	}
	cout << nz;
    } else {
	cout << 0;
    }
}