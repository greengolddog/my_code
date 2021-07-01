#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool dfs(ll v, ll p, vector<vector<ll>>& arr, vector<ll>& used, vector<ll>& parent, ll& ans) {
	parent[v] = p;
	used[v] = 1;
	for (auto i : arr[v]) {
		if (!used[i]) {
			if (dfs(i, v, arr, used, parent, ans)) {
				return true;
			}
		}
		if (used[i] == 1) {
			ans = v;
			parent[i] = v;
			return true;
		}
	}
	used[v] = 2;
	return false;
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
	vector<ll> used(n, 0);
	vector<ll> parent(n, 0);
	ll ans = 0;
	bool t = false;
	for (ll i = 0; i < n; i++) {
		if (dfs(i, -1, arr, used, parent, ans)) {
			t = true;
			break;
		}
	}
	if (t) {
		cout << "YES\n";
		vector<ll> a;
		ll now = ans;
		while (parent[now] != ans) {
			a.push_back(now);
			now = parent[now];
		}
		cout << now+1 << ' ';
		reverse(a.begin(), a.end());
		for (auto i : a) {
			cout << i+1 << ' ';
		}
	} else {
		cout << "NO";
	}
}
