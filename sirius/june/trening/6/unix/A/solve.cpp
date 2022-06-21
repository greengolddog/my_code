#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll INF32 = 2'000'000'000, INF64 = 9'000'000'000'000'000'000, LOG = 30;

ll solve(ll n) {
	vector<vector<bool>> precount(LOG, vector<bool>(n, true));
	for (ll i = 0; i < LOG; i++) {
		cout << i << endl;
		for (ll j = 0; j < min((1ll << i), n); j++) {
			if (i >= 2) {
				if ((j & 1) == ((j >> (i - 1)) & 1)) {
					precount[i][j] = precount[i - 2][(j & ((1 << (i - 1)) - 1)) >> 1];
				} else {
					precount[i][j] = false;
				}
				continue;
			}
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
		if (i % 1000 == 0) {
			cout << i << endl;
		}
		vector<ll> v;
		ll now = i;
		set<pair<ll, ll>> s;
		while (now > 0) {
			v.push_back(now % 2);
			s.insert(make_pair(1, now % 2));
			now /= 2;
		}
		for (ll l = 0; l < v.size(); l++) {
			ll r = min(l, (ll)v.size() - l - 1) + 1, k = 0;
			ll ms = r;
			while (r - k > 1) {
				ll mid = (k + r) / 2;
				ll nl = l - mid, nr = l + mid + 1;
				ll x = (i & ((1 << nr) - 1)) >> nl;
				if (s.find(make_pair(mid * 2 + 1, x)) == s.end()) {
					r = mid;
				} else {
					k = mid;
				}
			}
			for (ll sd = k; sd < ms; sd++) {
				ll nl = l - sd, nr = l + sd + 1;
				ll x = (i & ((1 << nr) - 1)) >> nl;
				if (!precount[sd * 2 + 1][x]) {
					break;
				}
				s.insert(make_pair(sd * 2 + 1, x));
			}
		}
		for (ll l = 0; l < v.size() - 1; l++) {
			ll r = min(l + 1, (ll)v.size() - l - 1) + 1, k = 1;
			ll ms = r;
			while (r - k > 1) {
				ll mid = (k + r) / 2;
				ll nl = l - mid + 1, nr = l + mid + 1;
				ll x = (i & ((1 << nr) - 1)) >> nl;
				if (s.find(make_pair(mid * 2, x)) == s.end()) {
					r = mid;
				} else {
					k = mid;
				}
			}
			for (ll sd = k; sd < ms; sd++) {
				ll nl = l - sd + 1, nr = l + sd + 1;
				ll x = (i & ((1 << nr) - 1)) >> nl;
				if (!precount[sd * 2][x]) {
					break;
				}
				s.insert(make_pair(sd * 2, x));
			}
		}
		ans += s.size() == v.size();
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
