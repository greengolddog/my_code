#include <bits/stdc++.h>
#define ll long long
#define elif else if
#define vecotr vector
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, x1, x2, y1, y2;
    char a;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vector<vector<ll>> arr(n*n, vector<ll>(0, 0));
	vector<pair<ll, ll>> ar(1, {-2, 1});
	ar.push_back({1, 2});
	ar.push_back({2, 1});
	ar.push_back({-2, -1});
	ar.push_back({2, -1});
	ar.push_back({-1, -2});
	ar.push_back({-1, 2});
	ar.push_back({1, -2});
    for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			for (auto k : ar) {
				if ((0 <= (i + k.first)) && (n > (i + k.first)) && (0 <= (j + k.second)) && (n > (j + k.second))) {
					arr[i * n + j].push_back((i + k.first) * n + j + k.second);
					// cout << i * n + j << ' ' << (i + k.first) * n + j + k.second << ' ' << i + k.first << ' ' << j + k.second << endl;
				}
			}
		}
	}
    vector<ll> dist(n*n, -1), pred(n*n, -1);
	// cout << dist[24] << endl;
    dist[(x1 - 1) * n + y1 - 1] = 0;
    queue<ll> q;
    q.push((x1 - 1) * n + y1 - 1);
    while (!q.empty()) {
	    ll v = q.front();
		// cout << v << endl;
	    q.pop();
	    for (auto i : arr[v]) {
			// cout << i << ' ';
	        if (dist[i] == -1) {
                pred[i] = v;
		        dist[i] = dist[v] + 1;
		        q.push(i);
	        }
        }
		// cout << endl;
    }
	cout << dist[(x2 - 1) * n + y2 - 1] << endl;
    ll now = (x2 - 1) * n + y2 - 1;
	dist.clear();
	vector<ll> ans(1, now);
	while (pred[now] != -1) {
		ans.push_back(pred[now]);
		now = pred[now];
	}
	reverse(ans.begin(), ans.end());
	for (auto i : ans) {
		cout << i / n + 1 << ' ' << i % n + 1 << endl;
	}
}
