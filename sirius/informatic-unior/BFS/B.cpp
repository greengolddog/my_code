#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<vector<bool>> arr(n+2, vector<bool>(m+2, false));
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			char c;
			cin >> c;
			if (c == '.') {
				arr[i][j] = true;
			}
		}
	}
	vector<vector<ll>> dist(n+2, vector<ll>(m+2, -1));
	vector<vector<char>> ans(n+2, vector<char>(m+2, '#'));
	queue<pair<ll, ll>> q;
	map<pair<ll, ll>, char> ma;
	ma[make_pair(0, -1)] = '>';
	ma[make_pair(-1, 0)] = 'v';
	ma[make_pair(0, 1)] = '<';
	ma[make_pair(1, 0)] = '^';
	vector<vector<bool>> used(n+2, vector<bool>(m+2, false));
	for (ll i = 1; i <= n; i++) {
		if (arr[i][1]) {
			used[i][1] = true;
			dist[i][1] = 0;
			q.push({i, 1});
			ans[i][1] = '<';
		}
	}
	for (ll i = 1; i <= n; i++) {
		if (arr[i][m]) {
			used[i][m] = true;
			dist[i][m] = 0;
			q.push({i, m});
			ans[i][m] = '>';
		}
	}
	for (ll i = 2; i < m; i++) {
		if (arr[1][i]) {
			used[1][i] = true;
			dist[1][i] = 0;
			q.push({1, i});
			ans[1][i] = '^';
		}
	}
	for (ll i = 2; i < m; i++) {
		if (arr[n][i]) {
			used[n][i] = true;
			dist[n][i] = 0;
			q.push({n, i});
			ans[n][i] = 'v';
		}
	}
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		for (ll i = -1; i <= 1; i++) {
			for (ll j = -1; j <= 1; j++) {
				if (abs(i) != abs(j)) {
					if (arr[now.first+i][now.second+j]) {
						if (!used[now.first+i][now.second+j]) {
							used[now.first+i][now.second+j] = true;
							dist[now.first+i][now.second+j] = dist[now.first][now.second]+1;
							q.push({now.first+i, now.second+j});
							ans[now.first+i][now.second+j] = ma[make_pair(i, j)];
						}
					}
				}
			}
		}
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			cout << ans[i][j];
		}
		cout << '\n';
	}
}
