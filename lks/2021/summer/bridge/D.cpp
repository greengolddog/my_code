#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void dfs(ll v, ll p, vector<vector<ll>>& arr, vector<ll>& dp, vector<bool>& used, ll hn, vector<ll>& ans, vector<ll>& h) {
	used[v] = true;
	dp[v] = hn;
	h[v] = hn;
	bool f = true;
	ll cnt = 0;
	for (auto i : arr[v]) {
		if (i == p) continue;
		if (used[i]) {
			dp[v] = min(dp[v], h[i]);
		} else {
			dfs(i, v, arr, dp, used, hn + 1, ans, h);
			if (dp[i] >= h[v]) {
				f = false;
			}
			cnt++;
			dp[v] = min(dp[v], dp[i]);
		}
	}
	if (p == -1) {
		if (cnt > 1) {
			ans.push_back(v);
		}
	} else {
		if (!f) {
			ans.push_back(v);
		}
	}
}

void dfs2(ll v, ll p, vector<bool>& used, vector<vector<ll>>& arr, vector<vector<pair<ll, ll>>>& a, unordered_set<ll>& all, ll now, vector<ll>& dp, vector<ll>& h) {
	used[v] = true;
	for (auto i : arr[v]) {
		if (!used[i]) {
			if (all.find(v) == all.end() || dp[i] < h[v]) {
				a[now].push_back({v, i});
				dfs2(i, v, used, arr, a, all, now, dp, h);
			} else {
				a.push_back(vector<pair<ll, ll>>(1, {v, i}));
				dfs2(i, v, used, arr, a, all, a.size()-1, dp, h);
			}
		} else {
			if (i != p) {
				if (v > i) {
					if (all.find(v) == all.end() || dp[i] < h[v]) {
						a[now].push_back({v, i});
					} else {
						a.push_back(vector<pair<ll, ll>>(1, {v, i}));
					}
				}
			}
		}
	}
}

int main() {
	freopen("biconv.in", "r", stdin);
	freopen("biconv.out", "w", stdout);
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> arr(n, vector<ll>(0, 0));
	map<pair<ll, ll>, vector<ll>> num;
	set<pair<ll, ll>> alll;
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		if (num.find({a, b}) == num.end()) {
			num[{a, b}] = vector<ll>(0, 0);
			num[{b, a}] = vector<ll>(0, 0);
		}
		num[{a, b}].push_back(i);
		num[{b, a}].push_back(i);
		alll.insert({a, b});
	}
	for (auto[a, b] : alll) {
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	vector<ll> dp(n, 0), h(n, 0);
	vector<bool> used(n, false);
	vector<ll> ans;
	for (ll i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i, -1, arr, dp, used, 0, ans, h);
		}
	}
	sort(ans.begin(), ans.end());
	unordered_set<ll> all;
	for (auto i : ans) {
		all.insert(i);
	}
	vector<vector<pair<ll, ll>>> aa;
	used.clear();
	used.resize(n, false);
	for (ll i = 0; i < n; i++) {
		if (!used[i]) {
			if (all.find(i) == all.end()) {
				aa.push_back(vector<pair<ll, ll>>(0, {0, 0}));
			}
			dfs2(i, -1, used, arr, aa, all, aa.size()-1, dp, h);
		}
	}
	vector<pair<ll, ll>> s;
	for (ll i = 0; i < aa.size(); i++) {
		for (auto j : aa[i]) {
			for (auto k : num[j]) {
				s.push_back({k, i+1});
			}
		}
	}
	sort(s.begin(), s.end());
	cout << aa.size() << '\n';
	for (auto[_, i] : s) {
		cout << i << ' ';
	}
}
