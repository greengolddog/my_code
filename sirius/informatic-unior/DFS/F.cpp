#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

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
	ll n, m, s, f;
	const ll INF = 1000000000000ll;
	cin >> n >> m >> s >> f;
	s--;
	f--;
	vector<vector<ll>> arr(n, vector<ll>(0, 0));
	vector<vector<pair<ll, ll>>> g(n, vector<pair<ll, ll>>(0, {0, 0}));
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back(b);
		ll c;
		cin >> c;
		g[b].push_back({a, c});
	}
	vector<ll> topsort;
	vector<ll> used(n, 0);
	for (ll i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i, used, arr, topsort);
		}
	}
	reverse(topsort.begin(), topsort.end());
	vector<ll> dp(n, INF);
	dp[s] = 0;
	for (auto i : topsort) {
		for (auto&[v, c] : g[i]) {
			if (dp[v] != INF) {
				dp[i] = min(dp[i], dp[v]+c);
			}
		}
	}
	if (dp[f] == INF) {
		cout << "Unreachable";
	} else {
		cout << dp[f];
	}
}
