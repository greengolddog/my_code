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
	ll a, b;
	cin >> a >> b;
	vector<vector<ll>> arr(a+b, vector<ll>(0, 0));
	for (ll i = 0; i < a; i++) {
		ll u;
		cin >> u;
		while (u != 0) {
			u--;
			arr[i].push_back(a+u);
			arr[a+u].push_back(i);
			cin >> u;
		}
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
	cout << count << '\n';
	for (ll i = 0; i < b; i++) {
		if (match[i] != -1) {
			cout << match[i]+1 << ' ' << i+1 << '\n';
		}
	}
}
