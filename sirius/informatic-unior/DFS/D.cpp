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
	vector<pair<ll, pair<ll, ll>>> r(m, {0, {0, 0}});
	for (ll i = 0; i < m; i++) {
		cin >> r[i].second.first >> r[i].second.second >> r[i].first;
	}
	sort(r.begin(), r.end());
	vector<pair<ll, ll>> g(m, {0, 0});
	for (ll i = 0; i < m; i++) {
		g[i] = r[i].second;
		g[i].first--;
		g[i].second--;
	}
	ll l = 0, rr = m;
	while (rr - l > 1) {
		ll mid = (l+rr)/2;
		vector<vector<ll>> arr(n, vector<ll>(0, 0));
		for (ll i = mid; i < m; i++) {
			arr[g[i].first].push_back(g[i].second);
			arr[g[i].second].push_back(g[i].first);
		}
		vector<bool> used(n, false);
		dfs(0, arr, used);
		bool f = true;
		for (auto i : used) {
			f = f && i;
		}
		if (f) {
			l = mid;
		} else {
			rr = mid;
		}
	}
	cout << r[l].first;
}
