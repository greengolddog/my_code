#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize(3)
#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
typedef int_fast32_t ll;

const ll INF = 1'000'000'000;

template<typename T>
bool assign_max(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll k, n, m;
	cin >> k >> n >> m;
	ll mm = m;
	string s;
	cin >> s;
	vector<vector<ll>> arr(n, vector<ll>(m));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	vector<pair<char, ll>> a(1, {s[0], 1});
	for (ll i = 1; i < k; i++) {
		if (s[i] == s[i - 1]) {
			a.back().second++;
		} else {
			a.emplace_back(s[i], 1);
		}
	}
	map<char, ll> ma;
	ma['W'] = 0;
	ma['N'] = 1;
	ma['E'] = 2;
	ma['S'] = 3;
	if (n <= 700 && m <= 700) {
		vector<ll> m((1 << 4) + 1, 0);
		for (ll i = 0; i <= (1 << 4); i++) {
			vector<bool> be(4, false);
			for (ll j = 0; j < 4; j ++) {
				be[j] = (i >> j) & 1;
			}
			ll now = 0;
			for (auto[c, col] : a) {
				if (be[ma[c]]) {
					now += col;
				} else {
					now = 0;
				}
				assign_max(m[i], now);
			}
			for (auto[c, col] : a) {
				if (be[ma[c]]) {
					now += col;
				} else {
					now = 0;
				}
				assign_max(m[i], now);
			}
			if (now == k * 2) {
				m[i] = INF;
			}
		}
		vector<pair<ll, ll>> go;
		go.push_back({0, -1});
		go.push_back({-1, 0});
		go.push_back({0, 1});
		go.push_back({1, 0});
		ll ans = INF, c = 0;
		vector<vector<bool>> used(n, vector<bool>(mm, false));
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < mm; j++) {
				if (arr[i][j] == 0) {
					continue;
				}
				used[i][j] = true;
				queue<pair<ll, ll>> q;
				vector<pair<ll, ll>> be;
				q.push({i, j});
				ll col = 1;
				while (!q.empty()) {
					be.push_back(q.front());
					auto[x, y] = q.front();
					q.pop();
					for (auto[ax, ay] : go) {
						if (ax + x >= 0 && ax + x < n && ay + y >= 0 && ay + y < mm && !used[ax + x][ay + y]) {
							ll now = 0;
							for (ll k = 0; k < 4; k++) {
								auto[aax, aay] = go[k];
								if (ax + x + aax >= 0 && ax + x + aax < n && ay + y + aay >= 0 && ay + y + aay < mm && used[x + ax + aax][y + ay + aay]) {
									now += (1 << k);
								}
							}
							if (m[now] >= arr[ax + x][ay + y] && arr[ax + x][ay + y] != 0) {
								used[x + ax][y + ay] = true;
								col++;
								q.push(make_pair(x + ax, y + ay));
							}
						}
					}
				}
				for (auto[x, y] : be) {
					used[x][y] = false;
				}
				c += (ans == col);
				if (assign_min(ans, col)) {
					c = 1;
				}
			}
		}
		cout << ans << ' ' << c << '\n';
		return 0;
	}
	ll max_W = 0, max_E = 0;
	for (auto[c, col] : a) {
		if (c == 'W') {
			assign_max(max_W, col);
		} else {
			assign_max(max_E, col);
		}
	}
	if (a.size() == 1) {
		if (max_W != 0) {
			max_W = INF;
		} else {
			max_E = INF;
		}
	}
	if (a[0].first == a.back().first) {
		if (a[0].first == 'W') {
			assign_max(max_W, a[0].second + a.back().second);
		} else {
			assign_max(max_E, a[0].second + a.back().second);
		}
	}
	ll ans = INF, col = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				continue;
			}
			ll l = j, r = j + 1;
			while (l > 0 && arr[i][l - 1] <= max_E && arr[i][l - 1] != 0) {
				l--;
			}
			while (r < m && arr[i][r] <= max_W && arr[i][r] != 0) {
				r++;
			}
			col += ans == (r - l);
			if (assign_min(ans, r - l)) {
				col = 1;
			}
		}
	}
	cout << ans << ' ' << col;
}
/*
⣿⣿⣿⣿⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣵⣿⣿⣿⠿⡟⣛⣧⣿⣯⣿⣝⡻⢿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⠋⠁⣴⣶⣿⣿⣿⣿⣿⣿⣿⣦⣍⢿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⢷⠄⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⢼⣿⣿⣿⣿
⢹⣿⣿⢻⠎⠔⣛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⣿⣿⣿⣿
⢸⣿⣿⠇⡶⠄⣿⣿⠿⠟⡛⠛⠻⣿⡿⠿⠿⣿⣗⢣⣿⣿⣿⣿
⠐⣿⣿⡿⣷⣾⣿⣿⣿⣾⣶⣶⣶⣿⣁⣔⣤⣀⣼⢲⣿⣿⣿⣿
⠄⣿⣿⣿⣿⣾⣟⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⢟⣾⣿⣿⣿⣿
⠄⣟⣿⣿⣿⡷⣿⣿⣿⣿⣿⣮⣽⠛⢻⣽⣿⡇⣾⣿⣿⣿⣿⣿
⠄⢻⣿⣿⣿⡷⠻⢻⡻⣯⣝⢿⣟⣛⣛⣛⠝⢻⣿⣿⣿⣿⣿⣿
⠄⠸⣿⣿⡟⣹⣦⠄⠋⠻⢿⣶⣶⣶⡾⠃⡂⢾⣿⣿⣿⣿⣿⣿
⠄⠄⠟⠋⠄⢻⣿⣧⣲⡀⡀⠄⠉⠱⣠⣾⡇⠄⠉⠛⢿⣿⣿⣿
⠄⠄⠄⠄⠄⠈⣿⣿⣿⣷⣿⣿⢾⣾⣿⣿⣇⠄⠄⠄⠄⠄⠉⠉
⠄⠄⠄⠄⠄⠄⠸⣿⣿⠟⠃⠄⠄⢈⣻⣿⣿⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⢿⣿⣾⣷⡄⠄⢾⣿⣿⣿⡄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠸⣿⣿⣿⠃⠄⠈⢿⣿⣿⠄⠄⠄⠄⠄⠄⠄
*/
