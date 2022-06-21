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
	vector<tuple<ll, ll, ll, ll>> q(m), nq, oo;
	for (auto&[r, l, k, v] : q) {
		cin >> l >> r >> k >> v;
		r++;
		if (v == 1) {
			k = r - l - k + 1;
		}
		v = 1 - v;
	}
	sort(q.begin(), q.end());
	vector<ll> ans(n, 0), col(n, 0);
	set<pair<ll, ll>> s;
	for (auto&[r, l, k, v] : q) {
		if (v == 0) {
			k -= r - l;
			oo.emplace_back(r, l, k, v);
		} else {
			for (ll i = l; i < r; i++) {
				col[i]++;
			}
			nq.emplace_back(r, l, k, v);
		}
	}
	for (ll i = 0; i < n; i++) {
		if (col[i] != 0) {
			s.insert(make_pair(col[i], i));
		}
	}
	while (!s.empty()) {
		auto[_, i] = *s.rbegin();
		s.erase(s.find(*s.rbegin()));
		bool b = false;
		for (auto&[r, l, k, v] : oo) {
			if (l <= i && i < r) {
				if (k == 0) {
					b = false;
					break;
				}
			}
		}
		if (b) {
			continue;
		}
		ans[i] = 1;
		for (auto&[r, l, k, v] : oo) {
			if (l <= i && i < r) {
				k++;
			}
		}
		for (auto&[r, l, k, v] : nq) {
			if (l <= i && i < r) {
				k--;
				if (k == 0) {
					for (ll j = l; j < r; j++) {
						col[j]--;
						if (s.find(make_pair(col[j] + 1, j)) != s.end()) {
							s.erase(make_pair(col[j] + 1, j));
							if (col[j] != 0) {
								s.insert(make_pair(col[j], j));
							}
						}
					}
				}
			}
		}
	}
	for (auto&[r, l, k, v] : nq) {
		if (k > 0) {
			cout << -1 << ' ';
			return;
		}
	}
	for (auto i : ans) {
		cout << 1 - i << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
