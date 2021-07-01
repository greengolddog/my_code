#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool dfs(ll v, vector<vector<ll>>& arr, vector<ll>& colour, ll now) {
	colour[v] = now;
	for (auto i : arr[v]) {
		if (!colour[i]) {
			if(!dfs(i, arr, colour, 3-now)) {
				return false;
			}
		} else {
			if (colour[i] == now) {
				return false;
			}
		}
	}
	return true;
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
	vector<ll> colour(n, 0);
	bool t = 1;
	for (ll i = 0; i < n; i++) {
		if (!colour[i]) {
			t = t & dfs(i, arr, colour, 1);
		}
	}
	if (t) {
		vector<ll> arr;
		for (ll i = 0; i < n; i++) {
			if (colour[i] == 1) {
				arr.push_back(i+1);
			}
		}
		cout << arr.size() << '\n';
		for (auto i : arr) {
			cout << i << ' ';
		}
	} else {
		cout << -1;
	}
}
