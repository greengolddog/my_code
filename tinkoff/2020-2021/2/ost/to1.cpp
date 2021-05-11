#include <bits/stdc++.h>
#define ll int64_t
#define elif else if

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
	vector<ll> used(n, 0);
	vector<ll> cost(n, 100000000);
	set<pair<ll, ll>> s;
	ll ans = 0;
	s.insert({0, 0});
	cost[0] = 0;
	while (!s.empty()) {
		ll now = (*(s.begin())).second;
		s.erase(s.begin());
		if (!used[now]) {
			ans += cost[now];
			used[now] = 1;
			for (auto i : arr[now]) {
				if (cost[i.first] > i.second) {
					cost[i.first] = i.second;
					s.insert({cost[i.first], i.first});
				}
			}
		}
	}
	cout << ans;
}
