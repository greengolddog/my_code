#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll rast(pair<ll, ll>& p1, pair<ll, ll>& p2) {
	return (p1.first - p2.first)*(p1.first-p2.first) + (p1.second - p2.second)*(p1.second - p2.second);
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	const ll INF = 1000000000;
	ll n;
	cin >> n;
	vector<pair<ll, ll>> arr(n, {0, 0});
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	ll s, t;
	cin >> s >> t;
	s--;
	t--;
	vector<ll> dist(n, INF);
	vector<bool> used(n, false);
	dist[s] = 0;
	for (ll _ = 0; _ < n; _++) {
		ll now = -1;
		for (ll i = 0; i < n; i++) {
			if (!used[i] && (now == -1 || dist[i] < dist[now])) {
				now = i;
			}
		}
		used[now] = true;
		for (ll i = 0; i < n; i++) {
			ll now_dist = dist[now]+rast(arr[now], arr[i]);
			if (dist[i] > now_dist) {
				dist[i] = now_dist;
			}
		}
	}
	cout << dist[t];
}
