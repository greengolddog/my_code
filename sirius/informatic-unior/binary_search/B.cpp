#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool check (__int128 a, __int128 k, __int128 b, __int128 m, __int128 n, __int128 x) {
	return ((a*(n-n/k))+(b*(n-n/m))) >= x;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll a, k, b, m, x;
	cin >> a >> k >> b >> m >> x;
	ll l = 0, r = x*2;
	while (r - l > 1) {
		ll mid = (l+r)/2;
		if (check(a, k, b, m, mid, x)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << r;
}
