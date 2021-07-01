#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void dfs(ll v, vector<vector<ll>>& arr, vector<bool>& used) {
	used[v] = true;
	for (auto i : arr[v]) {
		if (!used[i]) {
			dfs(i, arr, used);
		}
	}
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
		arr[b].push_back(a);
	}
	vector<bool> used(n, false);
	vector<ll> ans;
	dfs(0, arr, used);
	for (ll i = 1; i < n; i++) {
		if (!used[i]) {
			ans.push_back(i);
			dfs(i, arr, used);
		}
	}
	cout << ans.size() << '\n';
	for (auto i : ans) {
		cout << 1 << ' ' << i+1 << '\n';
	}
}
