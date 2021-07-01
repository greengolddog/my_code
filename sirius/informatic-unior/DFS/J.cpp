#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void dfs(ll v, ll p, vector<ll>& s, vector<vector<ll>>& arr, vector<vector<ll>>& z, vector<vector<pair<ll, ll>>>& ans) {
	s.push_back(v);
	for (ll i = 0; i < z[v].size(); i++) {
		ans[v][i].second = s[max(0ll, (ll)s.size()-z[v][i]-1)];
	}
	for (auto i : arr[v]) {
		if (i != p) {
			dfs(i, v, s, arr, z, ans);
		}
	}
	s.pop_back();
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<vector<ll>> arr(n, vector<ll>(0, 0));
	for (ll i = 1; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	ll m;
	cin >> m;
	vector<vector<pair<ll, ll>>> ans(n, vector<pair<ll, ll>>(0, {0, 0}));
	vector<vector<ll>> z(n, vector<ll>(0, 0));
	for (ll i = 0; i < m; i++) {
		ll v, k;
		cin >> v >> k;
		v--;
		z[v].push_back(k);
		ans[v].push_back({i, 0});
	}
	vector<ll> s(0, 0);
	dfs(0, -1, s, arr, z, ans);
	vector<pair<ll, ll>> a;
	for (ll i = 0; i < n; i++) {
		for (auto now : ans[i]) {
			a.push_back(now);
		}
	}
	sort(a.begin(), a.end());
	for (auto[_, q] : a) {
		cout << q+1 << '\n';
	}
}
