#include <bits/stdc++.h>
#define ll long long
#define elif else if
#define vecotr vector
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, a, b, maxm = 1;
	cin >> n;
	vector<vector<ll>> arr(n, vector<ll>(0, 0));
	for (ll i = 1; i < n; i++) {
		cin >> a >> b;
		arr[a - 1].push_back(b - 1);
		arr[b - 1].push_back(a - 1);
	}
	for (ll i = 0; i < n; i++) {
		vector<ll> dist(n, -1);
		// cout << dist[24] << endl;
		dist[i] = 1;
		queue<ll> q;
		q.push(i);
		while (!q.empty()) {
			ll v = q.front();
			// cout << v << endl;
			q.pop();
			for (auto i : arr[v]) {
				if (dist[i] == -1) {
					dist[i] = dist[v] + 1;
					maxm = max(maxm, dist[i]);
					q.push(i);
				}
			}
		}
	}
	cout << maxm;
}
