#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	freopen("dist.in", "r", stdin);
	freopen("dist.out", "w", stdout);
    	ll n, m, st, t;
    	cin >> n >> m >> st >> t;
	st--;
	t--;
    	vector<vector<pair<ll, ll>>> arr(n, vector<pair<ll, ll>>(0, {0, 0}));
    	for (ll i = 0; i < m; i++) {
	    	ll a, b, c;
	    	cin >> a >> b >> c;
	    	a--;
	    	b--;
	    	arr[a].push_back({b, c});
	    	arr[b].push_back({a, c});
	}
	vector<ll> used(n, 0);
	vector<ll> cost(n, 100000000);
	vector<ll> pred(n, 0);
	vector<ll> vp(n, 0);
	set<pair<ll, ll>> s;
	s.insert({0, st});
	cost[st] = 0;
	while (!s.empty()) {
		ll now = (*(s.begin())).second;
		s.erase(s.begin());
		if (!used[now]) {
			used[now] = 1;
			for (auto i : arr[now]) {
				if (cost[i.first] > (cost[now]+i.second)) {
					cost[i.first] = cost[now]+i.second;
					s.insert({cost[i.first], i.first});
					pred[i.first] = now;
					vp[i.first] = vp[now] + 1;
				}
			}
		}
	}
	if (cost[t] == 100000000) {
		cout << -1;
		return 0;
	}
	cout << cost[t] << endl << vp[t] + 1 << endl;
	vector<ll> way(1, t + 1);
	ll now = t;
	while (now != st) {
		now = pred[now];
		way.push_back(now + 1);
	}
	reverse(way.begin(), way.end());
	for (auto i : way) {
		cout << i << ' ';
	}
}
