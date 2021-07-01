#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void dfs(ll v, vector<bool>& near, vector<bool>& used, vector<vector<pair<ll, ll>>>& arr) {
	used[v] = true;
	for (auto[i, _] : arr[v]) {
		if (!used[i] && !near[i]) {
			dfs(i, near, used, arr);
		}
	}
}

void dfs2(ll v, ll p, vector<vector<pair<ll, ll>>>& arr, vector<ll>& col_cow, vector<ll>& col_t, vector<ll>& parent) {
	ll cc = 0, ct = 0;
	parent[v] = p;
	for (auto[i, _] : arr[v]) {
		if (i != p) {
			dfs2(i, v, arr, col_cow, col_t, parent);
			cc += col_cow[i];
			ct += col_t[i];
		}
	}
	col_cow[v] = cc;
	col_t[v] = ct;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m, to = -1;
	cin >> n >> m;
	bool one = true;
	ll cc = 0;
	vector<ll> type(n, 0);
	vector<bool> near(n, false);
	vector<vector<pair<ll, ll>>> arr(n, vector<pair<ll, ll>>(0, {0, 0}));
	for (ll i = 0; i < n; i++) {
		cin >> type[i];
		if (type[i] == 1) {
			to = i;
			cc++;
		}
	}
	for (ll i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		if (c != 0) {
			one = false;
		}
		if ((type[a] != type[b]) && (abs(type[a]) == abs(type[b]))) {
			cout << -1;
			return 0;
		}
		arr[a].push_back({b, c});
		arr[b].push_back({a, c});
	}
	if (one) {
		for (ll i = 0; i < n; i++) {
			if (type[i] == -1) {
				near[i] = true;
				for (auto[v, _] : arr[i]) {
					near[v] = true;
				}
			}
		}
		vector<bool> used(n, false);
		dfs(to, near, used, arr);
		bool possible = true;
		for (ll i = 0; i < n; i++) {
			if (type[i] == 1) {
				possible = possible && used[i];
			}
		}
		if (!possible) {
			cout << -1;
			return 0;
		}
		ll col = 0;
		vector<ll> ans;
		for (ll i = 0; i < n; i++) {
			if (near[i] && (type[i] != -1)) {
				col++;
				ans.push_back(i);
			}
		}
		cout << col << '\n';
		for (auto i : ans) {
			cout << i+1 << ' ';
		}
	} else {
		if (n <= 10) {
			vector<ll> dist(n, 100000000000000);
			set<pair<ll, ll>> s;
			for (ll i = 0; i < n; i++) {
				if (type[i] == 1) {
					dist[i] = 0;
					s.insert({0, i});
				}
			}
			while (!s.empty()) {
				auto[dn, now] = *s.begin();
				s.erase(s.begin());
				for (auto[v, c] : arr[now]) {
					if (dn+c < dist[v]) {
						s.erase({dist[v], v});
						dist[v] = dn + c;
						s.insert({dist[v], v});
					}
				}
			}
			ll bm = -1, mm = 1000000000000000;
			for (ll i = 0; i < (1 << n); i++) {
				vector<bool> near(n, false);
				bool f = false;
				for (ll j = 0; j < n; j++) {
					near[j] = (i >> j & 1);
					if (near[j] && (type[j] != 0)) {
						f = true;
						break;
					}
				}
				if (f) {
					continue;
				}
				vector<bool> used(n, false);
				dfs(to, near, used, arr);
				bool possible = true;
				for (ll j = 0; j < n; j++) {
					if (type[j] == 1) {
						possible = possible && used[j];
					}
					if (type[j] == -1) {
						possible = possible && (!used[j]);
					}
				}
				if (possible) {
					ll now = 0;
					for (ll j = 0; j < n; j++) {
						if (near[j]) {
							now = max(now, dist[j]);
						}
					}
					if (now < mm) {
						mm = now;
						bm = i;
					}
				}
			}
			if (bm == -1) {
				cout << -1;
			} else {
				ll col = 0;
				vector<ll> ans;
				for (ll i = 0; i < n; i++) {
					if ((bm >> i) & 1) {
						col++;
						ans.push_back(i+1);
					}
				}
				cout << col << '\n';
				for (auto i : ans) {
					cout << i << ' ';
				}
			}
		} else {
			if (cc == 1) {
				vector<ll> dist(n, 100000000000000);
				set<pair<ll, ll>> s;
				for (ll i = 0; i < n; i++) {
					if (type[i] == 1) {
						dist[i] = 0;
						s.insert({0, i});
					}
				}
				while (!s.empty()) {
					auto[dn, now] = *s.begin();
					s.erase(s.begin());
					for (auto[v, c] : arr[now]) {
						if (dn+c < dist[v]) {
							s.erase({dist[v], v});
							dist[v] = dn + c;
							s.insert({dist[v], v});
						}
					}
				}
				vector<ll> ad;
				for (ll i = 0; i < n; i++) {
					ad.push_back(dist[i]);
				}
				sort(ad.begin(), ad.end());
				ll l = -1, r = n-1;
				while (r - l > 1) {
					ll mid = (l+r)/2;
					vector<bool> near(n, false);
					for (ll i = 0; i < n; i++) {
						if (dist[i] <= ad[mid]) {
							if (type[i] == 0) {
								near[i] = true;
							}
						}
					}
					vector<bool> used(n, false);
					dfs(to, near, used, arr);
					bool possible = true;
					for (ll j = 0; j < n; j++) {
						if (type[j] == 1) {
							possible = possible && used[j];
						}
						if (type[j] == -1) {
							possible = possible && (!used[j]);
						}
					}
					if (possible) {
						r = mid;
					} else {
						l = mid;
					}
				}
				ll col = 0;
				vector<ll> ans;
				for (ll i = 0; i < n; i++) {
					if (dist[i] <= ad[r]) {
						if (type[i] == 0) {
							col++;
							ans.push_back(i+1);
						}
					}
				}
				cout << col << '\n';
				for (auto i : ans) {
					cout << i << ' ';
				}
			} else {
				vector<ll> col_cow(n, 0), col_t(n, 0), parent(n, 0);
				dfs2(0, 0, arr, col_cow, col_t, parent);
				vector<bool> del(n, false);
				ll col = 0;
				for (auto[v, _] : arr[0]) {
					col += (col_t[v] == 0);
				}
				if ((type[0] == 0) && (col == 1)) {
					del[0] = true;
				}
				for (ll i = 1; i < n; i++) {
					if ((type[i] == 0) && (col_t[i] == col_t[parent[i]])) {
						del[i] = true;
					}
				}
				col = 0;
				vector<ll> ans;
				if (del[0]) {
					  ll nu = -1;
					  for (auto[v, _] : arr[0]) {
						  if (!del[v]) {
							  nu = v;
							  break;
						  }
					  }
					  if (nu != -1) {
						  bool ec = false;
						  for (auto[v, _] : arr[0]) {
							  if (v != nu) {
								  if (col_cow[v] > 0 && !del[v]) {
									  ec = true;
									  break;
								  }
							  }
						  }
						  if (ec) {
							  col++;
							  ans.push_back(1);
						  }
				         }
				}
				for (ll i = 1; i < n; i++) {
					if (del[i] && (!del[parent[i]]) && (col_cow[i] > 0)) {
						col++;
						ans.push_back(i+1);
					}
				}
				vector<bool> used(n, false);
				dfs(to, del, used, arr);
				bool possible = true;
				for (ll j = 0; j < n; j++) {
					if (type[j] == 1) {
						possible = possible && used[j];
					}
					if (type[j] == -1) {
						possible = possible && (!used[j]);
					}
				}
				if (possible) {
					cout << col << '\n';
					for (auto i : ans) {
						cout << i << ' ';
					}
				} else {
					cout << -1;
				}
			}
		}
	}
}
