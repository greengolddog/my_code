#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

void dfs(ll v, ll p, vector<bool>& used, vector<ll>& size, vector<vector<ll>>& arr) {
	size[v] = 1;
	for (auto i : arr[v]) {
		if (i != p && !used[i]) {
			dfs(i, v, used, size, arr);
			size[v] += size[i];
		}
	}
}

void rec(ll v, ll n, vector<bool>& used, vector<vector<ll>>& arr) {
	vector<ll> size(n, 0);
	dfs(v, v, used, size, arr);
	ll cnt = v;
	ll sz = (size[v]) / 2;
	for (ll i = 0; i < n; i++) {
		if (size[i] == 0) {
			continue;
		}
		bool b = true;
		for (auto u : arr[i]) {
			if (size[u] > size[i]) {
				if (size[v] - size[i] > sz) {
					b = false;
					break;
				}
			} else {
				if (size[u] > sz) {
					b = false;
					break;
				}
			}
		}
		if (b) {
			cnt = i;
			break;
		}
	}
	used[cnt] = true;
	cout << cnt + 1 << endl;
	ll x;
	cin >> x;
	x--;
	if (x == -1) {
		cout << '!' << ' ' << cnt + 1 << endl;
		return;
	}
	rec(x, n, used, arr);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	vector<vector<ll>> arr(n);
	for (ll i = 1; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	vector<bool> used(n, false);
	rec(0, n, used, arr);
}
