#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef unsigned long long ull;

using namespace std;

ll n;
const ll MAXLG = 25;
vector<ll> dist;
vector<vector<ll>> binup;

ll lca(ll v, ll u) {
	if (dist[v] > dist[u]) {
		for (ll i = MAXLG - 1; i >= 0; i--) {
			ll to_v = binup[v][i];
			if (dist[to_v] >= dist[u]) v = to_v;
		}
	}
	if (dist[u] > dist[v]) {
		for (ll i = MAXLG - 1; i >= 0; i--) {
			ll to_u = binup[u][i];
			if (dist[to_u] >= dist[v]) u = to_u;
		}
	}
	if (v == u) {
		return v;
	}
	for (ll i = MAXLG - 1; i >= 0; i--) {
		ll to_v = binup[v][i], to_u = binup[u][i];
		if (to_v != to_u) {
			v = to_v;
			u = to_u;
		}
	}
	return binup[v][0];
}

void add(ll p) {
	dist.push_back(dist[p]+1);
	binup.push_back(vector<ll>(MAXLG, p));
	for (ll i = 1; i < MAXLG; i++) {
		binup[n][i] = binup[binup[n][i - 1]][i - 1];
	}
	n++;
}

ll get_dist(ll v, ll u) {
	ll l = lca(v, u);
	return dist[v]+dist[u]-2*dist[l];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll m, one = 0, two = 0, d = 0;
	n = 1;
	dist.resize(n, 0);
	binup.resize(n, vector<ll>(MAXLG, 0));
	cin >> m;
	for (ll i = 0; i < m; i++) {
		ll p;
		cin >> p;
		p--;
		add(p);
		ll dist_one = get_dist(one, n-1), dist_two = get_dist(two, n-1);
		if (max(dist_one, dist_two) > d) {
			if (dist_one > dist_two) {
				d = dist_one;
				two = n-1;
			} else {
				d = dist_two;
				one = n-1;
			}
		}
		cout << d << "\n";
	}
}
