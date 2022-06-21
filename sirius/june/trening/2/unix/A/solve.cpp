#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef int ll;

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

bool dfs(ll v, vector<bool>& used, vector<bool>& nu, vector<vector<ll>>& arr) {
	used[v] = true;
	nu[v] = true;
	for (auto i : arr[v]) {
		if (!used[i]) {
			if (dfs(i, used, nu, arr)) {
				return true;
			}
		} else {
			if (nu[i]) {
				return true;
			}
		}
	}
	nu[v] = false;
	return false;
}

bool check(ll l, ll r, ll n, ll k, vector<ll>& arr) {
	vector<vector<ll>> g(n);
	bool f = false;
	for (ll i = l; i < r; i++) {
		if (f) {
			g[arr[i]].push_back(arr[i + 1]);
		} else {
			g[arr[i + 1]].push_back(arr[i]);
		}
		f = !f;
	}
	vector<bool> used(k, false), nu(k, false);
	bool b = false;
	for (ll i = 0; i < k; i++) {
		if (!used[i]) {
			if (dfs(i, used, nu, g)) {
				b = true;
				break;
			}
		}
	}
	return !b;
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
	ll u = 0;
	for (ll i = 0; i < n; i++) {
		while (u < n && check(i, u, n, k, arr)) {
			u++;
		}
		ans[i] = u - 1;
	}
	for (ll _ = 0; _ < q; _++) {
		ll l, r;
		cin >> l >> r;
		l--;
		r--;
		cout << (r <= ans[l] ? "YES" : "NO") << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
