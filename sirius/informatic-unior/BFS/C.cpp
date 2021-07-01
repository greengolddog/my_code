#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	const ll INF = 1000000000000000;
	cin >> n >> m;
	vector<vector<pair<ll, ll>>> arr(n, vector<pair<ll, ll>>(0, {0, 0}));
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back({0, b});
		arr[b].push_back({1, a});
	}
	for (ll i = 0; i < n; i++) {
		sort(arr[i].begin(), arr[i].end());
	}
	vector<vector<ll>> dist(n, vector<ll>(n, -1));
	for (ll s = 0; s < n; s++) {
		vector<ll> d(n, INF);
		d[s] = 0;
		deque<ll> q;
		q.push_back(s);
		while (!q.empty()) {
			ll now = q.front();
			q.pop_front();
			for (auto&[c, v] : arr[now]) {
				if (c == 0) {
					if (d[now] < d[v]) {
						d[v] = d[now];
						q.push_front(v);
					}
				} else {
					if (d[now]+1 < d[v]) {
						d[v] = d[now]+1;
						q.push_back(v);
					}
				}
			}
		}
		for (ll i = 0; i < n; i++) {
			if (d[i] == INF) {
				d[i] = -1;
			}
		}
		dist[s] = d;
	}
	ll k;
	cin >> k;
	for (ll i = 0; i < k; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		cout << dist[a][b] << '\n';
	}	
}
