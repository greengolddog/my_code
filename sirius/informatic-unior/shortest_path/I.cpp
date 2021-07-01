#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct edge {
	ll a = 0, b = 0, c = 0;
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	const ll INF = 1000000000000000;
	ll n, m, k, s, f;
	cin >> n >> m >> k >> s >> f;
	s--;
	f--;
	map<pair<ll, ll>, ll> ma;
	for (ll i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		if (ma.find({a, b}) == ma.end()) {
			ma[make_pair(a, b)] = c;
		} else {
			ma[make_pair(a, b)] = min(ma[make_pair(a, b)], c);
		}
	}
	vector<edge> arr;
	for (auto[ab, c] : ma) {
		arr.push_back({ab.first, ab.second, c});
	}
	vector<vector<ll>> dist(n, vector<ll>(k+1, INF));
	dist[s][0] = 0;
	for (ll _ = 0; _ < n; _++) {
		for (auto&[a, b, c] : arr) {
			for (ll i = 0; i < k; i++) {
				dist[b][i+1] = min(dist[b][i+1], dist[a][i]+c);
			}
		}
	}
	ll ans = INF;
	for (auto i : dist[f]) {
		ans = min(ans, i);
	}
	cout << (ans > INF/100 ? -1 : ans);
}
