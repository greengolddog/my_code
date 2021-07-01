#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool dfs_loop(ll v, vector<vector<ll>>& arr, vector<ll>& used) {
	used[v] = 1;
	for (auto i : arr[v]) {
		if (!used[i]) {
			if (dfs_loop(i, arr, used)) {
				return true;
			}
		}
		if (used[i] == 1) {
			return true;
		}
	}
	used[v] = 2;
	return false;
}

void dfs(ll v, vector<ll>& used, vector<vector<ll>>& arr, vector<ll>& topsort) {
	used[v] = 1;
	for (auto i : arr[v]) {
		if (!used[i]) {
			dfs(i, used, arr, topsort);
		}
	}
	topsort.push_back(v);
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> arr(n, vector<ll>(0, 0));
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back(b);
	}
	vector<ll> topsort;
	vector<ll> used(n, 0);
	bool t = false;
	for (ll i = 0; i < n; i++) {
		t = t | dfs_loop(i, arr, used);
	}
	if (t) {
		cout << -1;
		return 0;
	}
	used.clear();
	used.resize(n, 0);
	for (ll i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i, used, arr, topsort);
		}
	}
	reverse(topsort.begin(), topsort.end());
	for (auto i : topsort) {
		cout << i+1 << ' ';
	}
}
