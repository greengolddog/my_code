#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll check(ll m, vector<ll>& arr, ll p, ll q) {
	__int128 c = 0;
	for (ll i : arr) {
		if (p != q) {
			if (i > q*m) {
				c += (i-q*m+p-q-1)/(p-q);
			}
			if (c > m) {
				return false;
			}
		} else {
			if (i > q*m) {
				return false;
			}
		}
	}
	return c <= m;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, q, p, maxx = 0;
	cin >> n >> p >> q;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		maxx = max(maxx, arr[i]);
	}
	ll l = 0, r = maxx;
	while (r - l > 1) {
		ll mid = (r+l)/2;
		if (check(mid, arr, p, q)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << r;
}
