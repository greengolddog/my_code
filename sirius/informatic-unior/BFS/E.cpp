#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	const ll INF = 1000000000000000;
	cin >> n >> m;
	vector<vector<ll>> t1(n, vector<ll>(0, 0)), t2(n, vector<ll>(0, 0));
	for (ll i = 0; i < m; i++) {
		ll a, b, t;
		cin >> a >> b >> t;
		a--;
		b--;
		if (t == 1) {
			t1[b].push_back(a);
		} else {
			t2[b].push_back(a);
		}
	}
	vector<ll> distt1(n, INF), distt2(n, INF);
	vector<bool> usedt1(n, false), usedt2(n, false);
	distt1[n-1] = 0;
	distt2[n-1] = 0;
	usedt1[n-1] = true;
	usedt2[n-1] = true;
	queue<pair<ll, ll>> q;
	q.push({n-1, 1});
	q.push({n-1, 2});
	while (!q.empty()) {
		ll now = q.front().first, t = q.front().second;
		q.pop();
		if (t == 1) {
			for (auto i : t2[now]) {
				if (!usedt2[i]) {
					usedt2[i] = true;
					distt2[i] = distt1[now]+1;
					q.push({i, 2});
				}
			}
		} else {	
			for (auto i : t1[now]) {
				if (!usedt1[i]) {
					usedt1[i] = true;
					distt1[i] = distt2[now]+1;
					q.push({i, 1});
				}
			}
		}
	}
	for (ll i = 0; i < n-1; i++) {
		ll now = min(distt1[i], distt2[i]);
		cout << (now == INF ? -1 : now) << ' ';
	}
}
