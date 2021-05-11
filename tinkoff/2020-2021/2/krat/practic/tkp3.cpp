#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

struct road {
	ll a;
	ll b;
	ll cost;
	road(ll a, ll b, ll cost): a(a), b(b), cost(cost) {}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
    	ll n, m, k, s, f;
    	cin >> n >> m >> k >> s >> f;
	s--;
	f--;
	set<pair<ll, ll>> keys;
	map<pair<ll, ll>, ll> roads_s;
	for (ll i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		if (keys.find({a, b}) != keys.end()) {
			roads_s[{a, b}] = min(roads_s[{a, b}], c);
			roads_s[{b, a}] = min(roads_s[{b, a}], c);
		} else {
			keys.insert({a, b});
			keys.insert({b, a});
			roads_s[{a, b}] = c;
			roads_s[{b, a}] = c;
		}
	}
	vector<road> roads;
	auto it = keys.begin();
	while (it != keys.end()) {
		roads.push_back(road(it->first, it->second, roads_s[*it]));
		it++;
	}
	vector<vector<ll>> ans(n, vector<ll>(k + 1, -1));
	for (ll i = 0; i <= k; i++) {
		ans[s][i] = 0;
	}
	for (ll i = 0; i < n; i++) {
		for (auto j : roads) {
			for (ll i = 0; i < k; i++) {
				if (ans[j.b][i] == -1) {
					if (ans[j.a][i+1] != -1) {
						ans[j.b][i] = ans[j.a][i+1] + j.cost;
					}
				} else {
					if (ans[j.a][i+1] != -1) {
						ans[j.b][i] = min(ans[j.a][i+1] + j.cost, ans[j.b][i]);
					}
				}
			}
		}
	}
	ll minn = -1;
	for (ll i = 0; i <= k; i++) {
		if (ans[f][i] != -1) {
			if (minn == -1) {
				minn = ans[f][i];
			} else {
				minn = min(minn, ans[f][i]);
			}
		}
	}
	cout << minn;
}
