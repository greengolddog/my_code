#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct edge {
	ll a = 0, t1 = 0, b = 0, t2 = 0;
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	const ll INF = 1000000000000000;
	ll n, s, f;
	cin >> n >> s >> f;
	ll m;
	cin >> m;
	vector<edge> arr(m);
	for (ll i = 0; i < m; i++) {
		cin >> arr[i].a >> arr[i].t1 >> arr[i].b >> arr[i].t2;
		arr[i].a--;
		arr[i].b--;
	}
	s--;
	f--;
	vector<ll> dist(n, INF);
	dist[s] = 0;
	for (ll _ = 0; _ < m; _++) {
		for (auto&[a, t1, b, t2] : arr) {
			if (t1 >= dist[a]) {
				dist[b] = min(dist[b], t2);
			}
		}
	}
	cout << dist[f];
}
