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
	ll n;
	cin >> n;
	ll m;
	cin >> m;
	ll k, s;
	cin >> k >> s;
	s--;
	vector<edge> arr(m);
	for (ll i = 0; i < m; i++) {
		cin >> arr[i].a >> arr[i].b >> arr[i].c;
		arr[i].a--;
		arr[i].b--;
	}
	vector<vector<ll>> dist(k+1, vector<ll>(n, INF));
	dist[0][s] = 0;
	for (ll i = 1; i <= k; i++) {
		for (auto&[a, b, c] : arr) {
			dist[i][b] = min(dist[i][b], dist[i-1][a]+c);
		}
	}
	for (auto i : dist[k]) {
		cout << (i > INF/100 ? -1 : i) << '\n';
	}
}
