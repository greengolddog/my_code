#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	const ll INF = 1000000000000000;
	ll h, w, sx, sy, fx, fy;
	cin >> h >> w >> sx >> sy >> fx >> fy;
	sx++;
	sy++;
	fx++;
	fy++;
	vector<vector<bool>> arr(h+4, vector<bool>(w+4, false));
	for (ll i = 2; i < h+2; i++) {
		for (ll j = 2; j < w+2; j++) {
			char c;
			cin >> c;
			if (c == '.') {
				arr[i][j] = true;
			}
		}	
	}
	vector<vector<ll>> dist(h+4, vector<ll>(w+4, INF));
	dist[sx][sy] = 0;
	deque<pair<ll, ll>> q;
	q.push_back({sx, sy});
	while (!q.empty()) {
		auto now = q.front();
		q.pop_front();
		for (ll i = -1; i <= 1; i++) {
			for (ll j = -1; j <= 1; j++) {
				if (abs(i) != abs(j)) {
					if (arr[now.first+i][now.second+j]) {
						if (dist[now.first+i][now.second+j] > dist[now.first][now.second]) {
							dist[now.first+i][now.second+j] = dist[now.first][now.second];
							q.push_front({now.first+i, now.second+j});
						}
					}
				}
			}
		}
		for (ll i = -2; i <= 2; i++) {
			for (ll j = -2; j <= 2; j++) {
				if (arr[now.first+i][now.second+j]) {
					if (dist[now.first+i][now.second+j] > dist[now.first][now.second]+1) {
						dist[now.first+i][now.second+j] = dist[now.first][now.second]+1;
						q.push_back({now.first+i, now.second+j});
					}
				}
			}
		}
	}
	cout << ((dist[fx][fy] == INF) ? -1 : dist[fx][fy]);
}
