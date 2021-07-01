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
	vector<edge> arr(m);
	for (ll i = 0; i < m; i++) {
		cin >> arr[i].a >> arr[i].b >> arr[i].c;
		arr[i].a--;
		arr[i].b--;
	}
	vector<ll> dist(n, INF);
	dist[0] = 0;
	for (ll _ = 0; _ < n; _++) {
		for (auto&[a, b, c] : arr) {
			dist[b] = min(dist[b], dist[a]+c);
		}
	}
	for (auto i : dist) {
		cout << (i > INF/100 ? 30000 : i) << ' ';
	}
}
