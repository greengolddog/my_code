#include <bits/stdc++.h>
typedef long long ll;
const ll INF = 1000000000000000;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<vector<pair<ll, ll>>> arr(n, vector<pair<ll, ll>>(0, {0, 0}));
	for (ll i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		arr[a].push_back({b, c});
		arr[b].push_back({a, c});
	}
	vector<ll> way;
	ll ans, st;
	{
		vector<ll> dist(n, INF), parent(n, -1);
		dist[0] = 0;
		vector<ll> used(n, false);
		set<pair<ll, ll>> s;
		s.insert({0, 0});
		while (!s.empty()) {
			auto[now, v] = *s.begin();
			s.erase(s.begin());
			used[v] = true;
			for (auto[i, c] : arr[v]) {
				if (dist[i] > now+c) {
					s.erase({dist[i], i});
					dist[i] = now+c;
					parent[i] = v;
					s.insert({dist[i], i});
				}
			}
		}
		ans = dist[n-1];
		st = dist[n-1];
		ll nn = n-1;
		while (nn != -1) {
			way.push_back(nn);
			nn = parent[nn];
		}
	}
	reverse(way.begin(), way.end());
	for (ll j = 0; j < way.size()-1; j++) {
		vector<ll> dist(n, INF);
		dist[0] = 0;
		vector<ll> used(n, false);
		set<pair<ll, ll>> s;
		s.insert({0, 0});
		while (!s.empty()) {
			auto[now, v] = *s.begin();
			s.erase(s.begin());
			used[v] = true;
			for (auto[i, c] : arr[v]) {
				if (v == way[j] && i == way[j+1]) {
					c = c*2;
				}
				if (dist[i] > now+c) {
					s.erase({dist[i], i});
					dist[i] = now+c;
					s.insert({dist[i], i});
				}
			}
		}
		ans = max(ans, dist[n-1]);
	}
	cout << ans-st;
}
