#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool dfs(ll u, vector<bool>& used, vector<ll>& match, vector<vector<ll>>& arr, ll a) {
	if (used[u]) {
		return false;
	}
	used[u] = true;
	for (auto v : arr[u]) {
		if (match[v-a] == -1 || dfs(match[v-a], used, match, arr, a)) {
			match[v-a] = u;
			return true;
		}
	}
	return false;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll a, b;
		cin >> a >> b;
		set<pair<ll, ll>> s;
		for (ll i = 0; i < a; i++) {
			for (ll j = 0; j < b; j++) {
				s.insert({i, a+j});
			}
		}
		vector<vector<ll>> arr(a+b, vector<ll>(0, 0));
		for (ll i = 0; i < a; i++) {
			ll u;
			cin >> u;
			while (u != 0) {
				u--;
				s.erase({i, a+u});
				cin >> u;
			}
		}
		for (auto[i, j] : s) {
			arr[i].push_back(j);
			arr[j].push_back(i);
		}
		vector<ll> match(b, -1);
		vector<bool> used(a, false);
		for (ll i = 0; i < a; i++) {
			if (dfs(i, used, match, arr, a)) {
				used.clear();
				used.resize(a+b, false);
			}
		}
		ll count = 0;
		for (ll i = 0; i < b; i++) {
			if (match[i] != -1) {
				count++;
			}
		}
		cout << a+b-count << '\n';
		cout << a << ' ' << b-count << '\n';
		for (ll i = 0; i < a; i++) {
			cout << i+1 << ' ';
		}
		cout << '\n';
		for (ll i = 0; i < b; i++) {
			if (match[i] == -1) {
				cout << i+1 << ' ';
			}
		}
		cout << '\n';
	}
}
