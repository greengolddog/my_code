#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, a, b, x, mini, now, cx, ccx;
    cin >> n;
    for (long long i = 0; i < n; i++) {
	cin >> a >> b;
	x = a;
	cx = x;
	if (x % b == 0) {
	    mini = x;
	    for (long long j = 2; j*j < x; j++) {
		if (x % j == 0) {
		    if (b % j == 0) {
			ccx = cx;
			now = 1;
			while (ccx % b == 0) {
			    x = x / j;
			    ccx = ccx / j;
			    now = now * j;
			}
			mini = min(mini, now);
			if (now == i) {
			    break;
			}
		    }
		}
	    }
	    if (x > 1) {
		if (b % x == 0) {
		    mini = min(mini, x);
		}
	    }
	    x = a / mini;
	}
	cout << x << "\n";
    }
}