#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m, q;
	cin >> n >> m >> q;
	vector<pair<ll, ll>> all;
	ll ans = 0;
	for (ll i = 0; i < q; i++) {
		ll l, r;
		cin >> l >> r;
		l--;
		r--;
		ans += (r - l) / m;
		r %= m;
		l %= m;
		if (l <= r) {
			all.push_back(make_pair(l, 1));
			all.push_back(make_pair(r + 1, -1));
		} else {
			all.push_back(make_pair(0, 1));
			all.push_back(make_pair(r + 1, -1));
			all.push_back(make_pair(l, 1));
		}
	}
	sort(all.begin(), all.end());
	ll mb = n, now = 0, last = 0;
	for (auto[a, b] : all) {
		if (a != last) {
			if (mb > now) {
				mb = now;
			}
		}
		now += b;
		last = a;
	}
	if (last < m - 1) {
		if (mb > now) {
			mb = now;
		}
	}
	cout << ans + mb;
}
