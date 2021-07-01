#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m, l;
	cin >> n >> m >> l;
	vector<vector<pair<ll, ll>>> arr(n, vector<pair<ll, ll>>(0, {0, 0}));
	for (ll i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		if (c <= l) {
			arr[a].push_back({b, c});
			arr[b].push_back({a, c});
		}
	}
	vector<vector<ll>> dist_all(n, vector<ll>(n, 0));
	for (ll k = 0; k < n; k++) {
		vector<ll> used(n, 0);
		vector<pair<ll, ll>> dist(n, {-1, -1});
		dist[k] = {0, 0};
		for (ll j = 0; j < n; j++) {
			ll now = -1;
			for (ll i = 0; i < n; i++) {
				if (used[i]) continue;
				if (now != -1) {
					if (dist[i].first != -1) {
						if (dist[i] < dist[now]) {
							now = i;
						}
					}
				} else {
					if (dist[i].first != -1) {
						now = i;
					}
				}
			}
			if (now == -1) {
				break;
			}
			used[now] = 1;
			for (auto i : arr[now]) {
				pair<ll, ll> d = dist[now];
				d.second += i.second;
				if (d.second > l) {
					d.second = i.second;
					d.first++;
				}
				if (dist[i.first].first == -1) {
					dist[i.first] = d;
				} else {
					dist[i.first] = min(dist[i.first], d);
				}
			}
		}
		for (ll i = 0; i < n; i++) {
			dist_all[k][i] = dist[i].first;
		}
	}
	ll q;
	cin >> q;
	for (ll i = 0; i < q; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		cout << dist_all[a][b] << '\n';
	}
}
