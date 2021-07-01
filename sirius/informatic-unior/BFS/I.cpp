#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct o {
	ll x, y, k;
	o(ll x = 0, ll y = 0, ll k = 0): x(x), y(y), k(k) {}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k, p, f;
	const ll INF = 1000000000000000;
	cin >> n >> k >> p >> f;
	vector<vector<bool>> arr(n*2+3, vector<bool>(n*2+3, true));
	for (ll i = 4; i < n*2+1; i += 2) {
		for (ll j = 3; j < n*2+2; j += 2) {
			ll now;
			cin >> now;
			arr[i][j] = now;
		}
	}
	for (ll i = 3; i < n*2+2; i += 2) {
		for (ll j = 4; j < n*2+1; j += 2) {
			ll now;
			cin >> now;
			arr[i][j] = now;
		}
	}
	p = p*2+1;
	f = f*2+1;
	vector<vector<vector<ll>>> dist(n*2+3, vector<vector<ll>>(n*2+3, vector<ll>(k+1, INF)));
	vector<vector<vector<bool>>> used(n*2+3, vector<vector<bool>>(n*2+3, vector<bool>(k+1, false)));
	dist[2][2][0] = 0;
	used[2][2][0] = true;
	for (ll i = 0; i < n*2+3; i++) {
		for (ll j = 0; j <= k; j++) {
			used[i][0][j] = true;
			used[i][1][j] = true;
			used[i][n*2+2][j] = true;
			used[i][n*2+1][j] = true;
		}
	}
	for (ll i = 0; i < n*2+3; i++) {
		for (ll j = 0; j <= k; j++) {
			used[0][i][j] = true;
			used[1][i][j] = true;
			used[n*2+2][i][j] = true;
			used[n*2+1][i][j] = true;
		}
	}
	queue<o> q;
	q.push(o(2, 2, 0));
	while (!q.empty()) {
		o now = q.front();
		q.pop();
		for (ll i = -1; i <= 1; i++) {
			for (ll j = -1; j <= 1; j++) {
				if (abs(i) != abs(j)) {
					cout << now.x << ' ' << now.y << ' ' << now.k << ' ' << now.x+i*2 << ' ' << now.y+j*2 << ' ' << dist[now.x][now.y][now.k] << ' ' << arr[now.x+i][now.y+j] << ' ' << used[now.x+i*2][now.y+j*2][now.k] << endl;
					if (arr[now.x+i][now.y+j]) {
						if (now.k+1 <= k) {
							if (!used[now.x+i*2][now.y+j*2][now.k+1]) {
								used[now.x+i*2][now.y+j*2][now.k+1] = true;
								dist[now.x+i*2][now.y+j*2][now.k+1] = dist[now.x][now.y][now.k]+1;
								q.push(o(now.x+i*2, now.y+j*2, now.k+1));
							}
						}
					} else {
						cout << 1 << endl;
						if (!used[now.x+i*2][now.y+j*2][now.k]) {
							cout << 1 << endl;
							used[now.x+i*2][now.y+j*2][now.k] = true;
							dist[now.x+i*2][now.y+j*2][now.k] = dist[now.x][now.y][now.k]+1;
							q.push(o(now.x+i*2, now.y+j*2, now.k));
						}
					}
				}
			}
		}
	}
	ll ans = INF;
	for (ll i = 0; i <= k; i++) {
		ans = min(ans, dist[p][f][i]);
	}
	cout << ((ans == INF) ? -1 : ans);
}
