#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF32 = 2'000'000'000, INF64 = 9'000'000'000'000'000'000;

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	b = a;
}

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
}

void solve() {
	ll n, k, q;
	cin >> n >> k >> q;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i]--;
	}
	vector<ll> ans(n, 0);
	for (ll i = 0; i < n; i++) {
		bool f = true;
		ll last = arr[i];
		ans[i] = i;
		vector<set<ll>> b(k), m(k);
		for (ll j = 0; j < k; j++) {
			b[j].insert(j);
			m[j].insert(j);
		}
		for (ll j = i + 1; j < n; (j++) && (ans[i]++)) {
			if (f) {
				if (b[arr[j]].find(last) != b[arr[j]].end()) {
					break;
				}
				set<ll> bj = b[arr[j]], ml = m[last];
				for (auto bb : bj) {
					for (auto mm : ml) {
						m[bb].insert(mm);
						b[mm].insert(bb);
					}
				}
			} else {
				if (b[last].find(arr[j]) != b[last].end()) {
					break;
				}
				set<ll> bj = b[last], ml = m[arr[j]];
				for (auto bb : bj) {
					for (auto mm : ml) {
						m[bb].insert(mm);
						b[mm].insert(bb);
					}
				}
			}
			f = !f;
			last = arr[j];
		}
	}
	for (ll _ = 0; _ < q; _++) {
		ll l, r;
		cin >> l >> r;
		l--;
		r--;
		cout << (ans[l] >= r ? "YES" : "NO") << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
