#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll INF32 = 2'000'000'000, INF64 = 9'000'000'000'000'000'000, LOG = 25;

ll solve(ll n) {
	vector<vector<bool>> precount(LOG, vector<bool>(n, true));
	for (ll i = 0; i < LOG; i++) {
		cout << i << endl;
		for (ll j = 0; j < min((1ll << (i + 1)), n); j++) {
			vector<ll> d;
			ll now = j;
			while (now > 0) {
				d.push_back(now % 2);
				now /= 2;
			}
			while (d.size() < i) {
				d.push_back(0);
			}
			for (ll k = 0; k < d.size() / 2; k++) {
				if (d[k] != d[d.size() - k - 1]) {
					precount[i][j] = false;
					break;
				}
			}
		}
	}
	cout << endl;
	ll ans = 0;
	for (ll i = 1; i < n; i++) {
		if (i % 100 == 0) {
			cout << i << endl;
		}
		vector<ll> v;
		ll now = i, nc = 0;
		while (now > 0) {
			v.push_back(now % 2);
			now /= 2;
		}
		set<pair<ll, ll>> s;
		for (ll l = 0; l < v.size(); l++) {
			for (ll r = l + 1; r <= v.size(); r++) {
				ll x = (i & ((1 << r) - 1)) >> l;
				if (s.find(make_pair(r - l, x)) != s.end()) {
					continue;
				}
				bool b = precount[r - l][x];
				nc += b;
				if (b) {
					s.insert(make_pair(r - l, x));
				}
				if (nc > v.size()) {
					break;
				}
			}
			if (nc > v.size()) {
				break;
			}
		}
		ans += nc == v.size();
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	cout << solve(n);
}
