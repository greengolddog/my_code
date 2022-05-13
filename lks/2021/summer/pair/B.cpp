#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool dfs(ll u, vector<bool>& used, vector<ll>& match, vector<vector<ll>>& arr, ll a) {
	if (used[u]) {
		return false;
	}
	used[u] = true;
	for (auto v : arr[u]) {
		if (match[v - a] == -1 || dfs(match[v - a], used, match, arr, a)) {
			match[v - a] = u;
			return true;
		}
	}
	return false;
}

void dfs(ll u, vector<bool>& used, vector<vector<ll>>& arr) {
	used[u] = true;
	for (auto v : arr[u]) {
		if (!used[v]) {
			dfs(v, used, arr);
		}
	}
}

int main() {
	freopen("min-dominating-set.in", "r", stdin);
	freopen("min-dominating-set.out", "w", stdout);
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll a, b;
	cin >> a >> b;
	vector<vector<ll>> arr(a + b, vector<ll>(0, 0));
	ll u, v;
	while (cin >> u) {
		cin >> v;
		u--;
		v--;
		arr[u].push_back(a + v);
		arr[a + v].push_back(u);
	}
	vector<ll> match(b, -1);
	vector<bool> used(a, false);
	for (ll i = 0; i < a; i++) {
		if (dfs(i, used, match, arr, a)) {
			used.clear();
			used.resize(a + b, false);
		}
	}
	set<pair<ll, ll>> s;
	for (ll i = 0; i < a + b; i++) {
		for (auto j : arr[i]) {
			s.insert({min(i, j), max(i, j)});
		}
	}
	for (ll i = 0; i < b; i++) {
		if (match[i] != -1) {
			s.insert({a + i, match[i]});
			s.erase({match[i], a + i});
		}
	}
	vector<vector<ll>> new_arr(a + b, vector<ll>(0, 0));
	for (auto[u, v] : s) {
		new_arr[u].push_back(v);
	}
	set<ll> s1;
	for (ll i = 0; i < a; i++) {
		s1.insert(i);
	}
	for (ll i = 0; i < b; i++) {
		if (match[i] != -1) {
			s1.erase(match[i]);
		}
	}
	used.clear();
	used.resize(a + b, false);
	for (auto i : s1) {
		dfs(i, used, new_arr);
	}
	ll cnt1 = 0, cnt2 = 0;
	for (ll i = 0; i < a; i++) {
		if (!used[i]) {
			cnt1++;
		}
	}
	for (ll i = a; i < a + b; i++) {
		if (used[i]) {
			cnt2++;
		}
	}
	cout << cnt1 + cnt2 << '\n';
	cout << cnt1 << ' ' << cnt2 << '\n';
	for (ll i = 0; i < a; i++) {
		if (!used[i]) {
			cout << i + 1 << ' ';
		}
	}
	cout << '\n';
	for (ll i = a; i < a + b; i++) {
		if (used[i]) {
			cout << i - a + 1 << ' ';
		}
	}
}
