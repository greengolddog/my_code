#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	ll m;
	cin >> m;
	vector<vector<ll>> arr(n, vector<ll>(0, 0));
	for (ll i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back(b);
	}
	ll s, t;
	cin >> s >> t;
	s--;
	t--;
	vector<ll> dist(n, -1);
	vector<ll> pred(n, -1);
	vector<bool> used(n, false);
	used[s] = true;
	queue<ll> q;
	q.push(s);
	dist[s] = 0;
	while (!q.empty()) {
		ll now = q.front();
		q.pop();
		for (auto i : arr[now]) {
			if (!used[i]) {
				used[i] = true;
				dist[i] = dist[now]+1;
				pred[i] = now;
				q.push(i);
			}
		}
	}
	cout << dist[t] << '\n';
	if (dist[t] != -1) {
		ll now = t;
		vector<ll> ans;
		while (now != -1) {
			ans.push_back(now);
			now = pred[now];
		}
		reverse(ans.begin(), ans.end());
		for (auto i : ans) {
			cout << i+1 << ' ';
		}
	}
}
