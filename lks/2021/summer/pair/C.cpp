#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool dfs(ll u, vector<bool>& used, vector<ll>& match, vector<vector<ll>>& arr, ll a) {
	if (used[u]) {
		return false;
	}
	used[u] = true;
	for (auto v : arr[u]) {
		if (match[v-a] == -1 || dfs(match[v-a], used, match, arr, a)) {
			match[v-a] = u;
			return true;
		}
	}
	return false;
}

ll dist(pair<pair<ll, ll>, pair<ll, ll>> p) {
	return abs(p.first.first-p.second.first)+abs(p.first.second-p.second.second);
}

int main() {
	freopen("taxi.in", "r", stdin);
	freopen("taxi.out", "w", stdout);
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll a, b;
	cin >> a;
	b = a;
	vector<pair<ll, pair<pair<ll, ll>, pair<ll, ll>>>> all(a, {0, {{0, 0}, {0, 0}}});
	for (ll i = 0; i < a; i++) {
		ll h, m;
		char _;
		cin >> h >> _ >> m;
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		all[i] = {h*60+m, {{x1, y1}, {x2, y2}}};
	}
	vector<vector<ll>> arr(a+b, vector<ll>(0, 0));
	for (ll i = 0; i < a; i++) {
		for (ll j = 0; j < a; j++) {
			if (all[i].first+dist(all[i].second)+dist({all[i].second.second, all[j].second.first}) < all[j].first) {
				arr[i].push_back(j+a);
				arr[j+a].push_back(i);
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
	ll count = 0;
	for (ll i = 0; i < b; i++) {
		if (match[i] == -1) {
			count++;
		}
	}
	cout << count << '\n';
}
