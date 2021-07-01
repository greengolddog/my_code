#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
    	string n;
    	cin >> n;
    	ll k;
    	cin >> k;
    	ll ost = 0;
    	for (ll i = 0; i < n.size(); i++) {
		ost = (ost*10 + (n[i] - '0'))%k;
	}
	vector<vector<ll>> arr(k, vector<ll>(0, 0));
	ll m;
	cin >> m;
	vector<ll> d(m, 0);
	for (ll i = 0; i < m; i++) {
		cin >> d[i];
	}
	sort(d.begin(), d.end());
	for (ll i = 0; i < k; i++) {
		for (ll j = 0; j < m; j++) {
			arr[i].push_back((i*10+d[j])%k);
		}
	}
	vector<ll> used(k, 0);
	vector<ll> dist(k, -1);
	vector<ll> pred(k, 0);
	used[ost] = 1;
	pred[ost] = -1;
	dist[ost] = 0;
	queue<ll> q;
	q.push(ost);
	while (!q.empty()) {
		ll now = q.front();
		q.pop();
		for (auto i : arr[now]) {
			if (!used[i]) {
				used[i] = 1;
				pred[i] = now;
				dist[i] = dist[now] + 1;
				q.push(i);
			}
		}
	}
	if (dist[0] == -1) {
		cout << -1;
		return 0;
	}
	ll i = 0;
	vector<ll> ans(0, 0);
	while (i != ost) {
		for (auto j : d) {
			if ((pred[i]*10+j)%k == i) {
				ans.push_back(j);
				break;
			}
		}
		i = pred[i];
	}
	reverse(ans.begin(), ans.end());
	for (i = 0; i < ans.size(); i++) {
		n += to_string(ans[i]);
	}
	cout << n;
}
