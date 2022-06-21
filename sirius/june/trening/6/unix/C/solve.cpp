#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll INF32 = 2'000'000'000, INF64 = 9'000'000'000'000'000'000, LOG = 25;

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

bool check(vector<vector<char>> arr, ll n, ll m, ll sx, ll sy, ll ex, ll ey, ll rv) {
	vector<pair<ll, ll>> go, go2;
	go.emplace_back(0, 1);
	go.emplace_back(0, -1);
	go.emplace_back(1, 0);
	go.emplace_back(-1, 0);
	for (ll i = -1; i <= 1; i++) {
		for (ll j = -1; j <= 1; j++) {
			go2.push_back(make_pair(i, j));
		}
	}
	vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF32));
	dist[sx][sy] = 0;
	queue<pair<ll, ll>> q;
	q.push(make_pair(sx, sy));
	while (!q.empty()) {
		auto[x, y] = q.front();
		q.pop();
		for (auto[xp, yp] : go) {
			if (arr[x + xp][y + yp] == '.' && assign_min(dist[x + xp][y + yp], 0ll)) {
				q.push(make_pair(x + xp, y + yp));
			}
		}
	}
	for (ll i = 0; i < m; i++) {
		while (!q.empty()) {
			q.pop();
		}
		for (ll j = 0; j <= n; j++) {
			for (ll k = 0; k <= n; k++) {
				if (dist[j][k] == 0) {
					q.push(make_pair(j, k));
				}
			}
		}
		while (!q.empty()) {
			auto[x, y] = q.front();
			q.pop();
			for (auto[xp, yp] : go2) {
				if (arr[x + xp][y + yp] != '*' && assign_min(dist[x + xp][y + yp], dist[x][y] + 1)) {
					q.push(make_pair(x + xp, y + yp));
				}
			}
		}
		for (ll j = 0; j <= n; j++) {
			for (ll k = 0; k <= n; k++) {
				if (dist[j][k] <= rv) {
					dist[j][k] = 0;
				} else {
					dist[j][k] = INF32;
				}
			}
		}
		while (!q.empty()) {
			q.pop();
		}
		for (ll j = 0; j <= n; j++) {
			for (ll k = 0; k <= n; k++) {
				if (dist[j][k] == 0) {
					q.push(make_pair(j, k));
				}
			}
		}
		while (!q.empty()) {
			auto[x, y] = q.front();
			q.pop();
			for (auto[xp, yp] : go) {
				if (arr[x + xp][y + yp] == '.' && assign_min(dist[x + xp][y + yp], 0ll)) {
					q.push(make_pair(x + xp, y + yp));
				}
			}
		}
	}
	return dist[ex][ey] == 0;
}

bool checks(vector<vector<char>> arr, ll n, ll m, ll sx, ll sy, ll ex, ll ey, ll rv) {
	if (m == 2) {
		vector<pair<ll, ll>> go;
		go.emplace_back(0, 1);
		go.emplace_back(0, -1);
		go.emplace_back(1, 0);
		go.emplace_back(-1, 0);
		vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF32));
		dist[sx][sy] = 0;
		queue<pair<ll, ll>> q;
		q.push(make_pair(sx, sy));
		while (!q.empty()) {
			auto[x, y] = q.front();
			q.pop();
			for (auto[xp, yp] : go) {
				if (arr[x + xp][y + yp] == '.' && assign_min(dist[x + xp][y + yp], 0ll)) {
					q.push(make_pair(x + xp, y + yp));
				}
			}
		}
		vector<vector<char>> narr = arr;
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= n; j++) {
				if (dist[i][j] == 0) {
					for (ll k = -rv; k <= rv; k++) {
						for (ll o = -rv; o <= rv; o++) {
							if (j + k > 0 && j + k <= n && i + o > 0 && i + o <= n) {
								arr[j + k][i + o] = '.';
							}
						}
					}
					if (check(arr, n, 1, sx, sy, ex, ey, rv)) {
						return true;
					}
					arr = narr;
				}
			}
		}
		return false;
	} else {
		return check(arr, n, m, sx, sy, ex, ey, rv);
	}
}

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<vector<char>> arr(n + 2, vector<char>(n + 2, '*'));
	ll sx, sy, ex, ey;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			char c;
			cin >> c;
			arr[i][j] = c;
			if (c == 'A') {
				sx = i;
				sy = j;
				arr[i][j] = '.';
			}
			if (c == 'B') {
				ex = i;
				ey = j;
				arr[i][j] = '.';
			}
		}
	}
	ll l = -1, r = n + 1;
	while (r - l > 1) {
		ll mid = (l + r) / 2;
		if (check(arr, n, m, sx, sy, ex, ey, mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	if (r == 0) {
		cout << -1 << '\n';
	} else {
		cout << r << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
