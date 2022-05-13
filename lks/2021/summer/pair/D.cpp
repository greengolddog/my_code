#include <bits/stdc++.h>
typedef __int128 ll;

using namespace std;

bool dfs(ll u, vector<bool>& used, vector<ll>& match, vector<vector<ll>>& arr, ll a) {
	if (used[u]) {
		return false;
	}
	used[u] = true;
	for (auto v : arr[u]) {
		if (match[v - a] == -1 || dfs(match[v - a], used, match, arr, a)) {
			match[v-a] = u;
			return true;
		}
	}
	return false;
}

int main() {
	freopen("dominoes.in", "r", stdin);
	freopen("dominoes.out", "w", stdout);
	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll a = 0, b = 0, n, m, c2, c1;
	long long nc, mc, c1c, c2c;
	cin >> nc >> mc >> c2c >> c1c;
	n = nc;
	m = mc;
	c2 = c2c;
	c1 = c1c;
	map<pair<ll, ll>, ll> num;
	vector<vector<ll>> arr(0, vector<ll>(0, 0)), all(n + 2, vector<ll>(m + 2, 0));
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			char c;
			cin >> c;
			all[i][j] = c == '*';
			if (all[i][j]) {
				arr.push_back(vector<ll>(0, 0));
				a += (i + j + 1) % 2;
				b += (i + j) % 2;
			}
		}
	}
	if (c1 * 2 <= c2) {
		cout << (long long)(c1 * (a + b));
		return 0;
	}
	ll u1 = 0, u2 = a;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			if (all[i][j]) {
				if ((i + j) % 2 == 0) {
					num[make_pair(i, j)] = u1;
					u1++;
				} else {
					num[make_pair(i, j)] = u2;
					u2++;
				}
			}
		}
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			if (all[i][j]) {
				if (all[i - 1][j]) {
					arr[num[make_pair(i, j)]].push_back(num[make_pair(i - 1, j)]);
				}
				if (all[i + 1][j]) {
					arr[num[make_pair(i, j)]].push_back(num[make_pair(i + 1, j)]);
				}
				if (all[i][j - 1]) {
					arr[num[make_pair(i, j)]].push_back(num[make_pair(i, j - 1)]);
				}
				if (all[i][j + 1]) {
					arr[num[make_pair(i, j)]].push_back(num[make_pair(i, j + 1)]);
				}
			}
		}

	}
	vector<ll> match(b, -1);
	vector<bool> used(a, false);
	for (ll i = 0; i < a; i++) {
		if (dfs(i, used, match, arr, a)) {
			used.clear();
			used.resize(a, false);
		}
	}
	ll ans = (a + b) * c1;
	for (ll i = 0; i < b; i++) {
		if (match[i] != -1) {
			ans += c2;
			ans -= c1 * 2;
		}
	}
	cout << (long long)ans;
}
