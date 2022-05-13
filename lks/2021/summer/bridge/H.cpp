#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

void dfs(ll v, ll p, vector<vector<ll>>& arr, vector<ll>& dp, vector<bool>& used, ll hn, vector<pair<ll, ll>>& ans, vector<ll>& h) {
	used[v] = true;
	dp[v] = hn;
	h[v] = hn;
	for (auto i : arr[v]) {
		if (i == p) continue;
		if (used[i]) {
			dp[v] = min(dp[v], h[i]);
		} else {
			dfs(i, v, arr, dp, used, hn + 1, ans, h);
			if (dp[i] > h[v]) {
				ans.push_back({v, i});
			}
			dp[v] = min(dp[v], dp[i]);
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
	vector<ll> dp(n, 0), h(n, 0);
	vector<bool> used(n, false);
	vector<pair<ll, ll>> ans;
	for (ll i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i, -1, arr, dp, used, 0, ans, h);
		}
	}
	set<pair<ll, ll>> a;
	for (auto[x, y] : ans) {
		a.insert({x, y});
		a.insert({y, x});
	}
	ll s, f;
	cin >> s >> f;
	s--;
	f--;
	vector<ll> pred(n, -1);
	used.clear();
	used.resize(n, false);
	used[s] = true;
	queue<ll> q;
	q.push(s);
	while (!q.empty()) {
		ll now = q.front();
		q.pop();
		for (auto i : arr[now]) {
			if (!used[i]) {
				used[i] = true;
				pred[i] = now;
				q.push(i);
			}
		}
	}
	ll now = f;
	set<ll> aa;
	while (pred[now] != -1) {
		if (a.find({now, pred[now]}) != a.end()) {
			aa.insert(now);
			aa.insert(pred[now]);
		}
		now = pred[now];
	}
	aa.erase(s);
	aa.erase(f);
	cout << aa.size() << '\n';
	for (auto i : aa) {
		cout << i + 1 << ' ';
	}
}
