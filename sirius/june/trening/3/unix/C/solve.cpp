#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll INF32 = 2'000'000'000, INF64 = 9'000'000'000'000'000'000;
mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	deque<pair<ll, ll>> all;
	vector<ll> razn(n + 1, 0);
	for (ll i = 0; i < m; i++) {
		ll l, r;
		cin >> l >> r;
		l--;
		razn[l]++;
		razn[r]--;
		all.push_back(make_pair(l, r));
	}
	sort(all.begin(), all.end());
	for (ll i = 1; i <= n; i++) {
		razn[i] += razn[i - 1];
	}
	for (ll i = 0; i < n; i++) {
		a[i] -= razn[i];
	}
	multiset<ll> r, opr;
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		while (!all.empty() && all.front().first == i) {
			r.insert(all.front().second);
			all.pop_front();
		}
		while (!opr.empty() && *opr.begin() == i) {
			opr.erase(opr.begin());
		}
		while (!r.empty() && *r.begin() == i) {
			r.erase(r.begin());
		}
		a[i] += opr.size();
		while (a[i] < 0) {
			if (r.empty()) {
				cout << -1 << '\n';
				return;
			}
			opr.insert(*r.rbegin());
			r.erase(r.find(*r.rbegin()));
			a[i]++;
			ans++;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
