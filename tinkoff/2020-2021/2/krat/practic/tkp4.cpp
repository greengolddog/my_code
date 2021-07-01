#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
    	ll n, m;
    	vector<ll> start(0, 0), finish(0, 0);
    	cin >> n >> m;
    	for (ll i = 0; i < n; i++) {
	    	ll inp;
	    	cin >> inp;
	 	if (inp == 1) {
			start.push_back(i);
		}
		if (inp == 2) {
			finish.push_back(i);
		}
	}
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
	vector<ll> dist(n, -1);
	vector<ll> fir(n, 0);
	for (auto i : start) {
		dist[i] = 0;
		fir[i] = i;
	}
	for (ll i = 0; i < n; i++) {
		ll now = -1;
		for (ll j = 0; j < n; j++) {
			if (used[j]) continue;
			if (dist[j] != -1) {
				if (now == -1) {
					now = j;
				} else {
					if (dist[now] > dist[j]) {
						now = j;
					}
				}
			}
		}
		if (now == -1) {
			break;
		}
		used[now] = 1;
		for (auto j : arr[now]) {
			if ((dist[now] + j.second < dist[j.first]) || (dist[j.first] == -1)) {
				fir[j.first] = fir[now];
				dist[j.first] = dist[now] + j.second;
			}
		}
	}
	ll ans = -1;
	for (auto i : finish) {
		if (dist[i] != -1) {
			if ((ans == -1) || (dist[ans] > dist[i])) {
				ans = i;
			}
		}
	}
	if (ans == -1) {
		cout << -1;
		return 0;
	}
	cout << fir[ans] + 1 << ' ' << ans + 1 << ' ' << dist[ans] << endl;
}
