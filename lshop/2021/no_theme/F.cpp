#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll dfs(ll v, ll h, vector<vector<ll>>& arr, ll maxh, vector<bool>& used) {
	if (h > maxh) {
		return 0;
	}
	used[v] = true;
	ll cnt = 0;
	for (auto i : arr[v]) {
		if (!used[i]) {
			cnt += dfs(i, h+1, arr, maxh, used);
		}
	}
	return cnt+1;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	vector<vector<ll>> arr(n, vector<ll>(0, 0));
	vector<pair<ll, ll>> all;
	for (ll i = 1; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		all.push_back({a, b});
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	if (k % 2 == 0) {
		ll ans = 0;
		for (ll i = 0; i < n; i++) {
			vector<bool> used(n, false);
			ans = max(ans, dfs(i, 0, arr, k/2, used));
		}
		cout << n-ans;
	} else {
		ll ans = 0;
		for (auto[a, b] : all) {
			vector<bool> used(n, false), used2(n, false);
			ll cnt = 0;
			dfs(a, 0, arr, k/2, used);
			dfs(b, 0, arr, k/2, used2);
			for (ll i = 0; i < n; i++) {
				if (used[i] || used2[i]) {
					cnt++;
				}
			}
			ans = max(ans, cnt);
		}
		cout << n-ans;
	}
}
