#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void dfs(ll v, vector<multiset<ll>>& arr, vector<ll>& ans) {
	while (!arr[v].empty()) {
		ll u = *arr[v].begin();
		arr[v].erase(arr[v].find(u));
		arr[u].erase(arr[u].find(v));
		dfs(u, arr, ans);
	}
	ans.push_back(v);
}

int main() {
	freopen("post.in", "r", stdin);
	freopen("post.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, s = 0;
	cin >> n;
	multiset<ll> v;
	vector<multiset<ll>> arr(n, v);
	for (ll i = 0; i < n; i++) {
		ll m;
		cin >> m;
		s += m;
		for (ll j = 0; j < m; j++) {
			ll x, c;
			cin >> x >> c;
			x--;
			arr[i].insert(x);
		}
	}
	vector<ll> ans;
	bool b = true;
	for (ll i = 0; i < n; i++) {
		if (arr[i].size() % 2 == 1) {
			b = false;
			dfs(i, arr, ans);
			break;
		}
	}
	if (b) {
		dfs(0, arr, ans);
	}
	ll sum = 0;
	for (auto& i : arr) {
		sum += i.size();
	}
	if (sum != 0) {
		cout << -1;
	} else {
		cout << ans.size() - 1 << '\n';
		for (auto i : ans) {
			cout << i + 1 << ' ';
		}
	}
}
