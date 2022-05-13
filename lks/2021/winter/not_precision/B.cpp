#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000;

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

mt19937_64 rnd(time(0) + 1);

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll b, s, f;
	cin >> b >> s >> f;
	vector<pair<ll, ll>> go(1, {0, 0});
	go.push_back({1, 0});
	go.push_back({-1, 0});
	go.push_back({0, 1});
	go.push_back({0, -1});
	map<pair<ll, ll>, char> cgo;
	cgo[make_pair(0, -1)] = 'L';
	cgo[make_pair(0, 1)] = 'R';
	cgo[make_pair(-1, 0)] = 'U';
	cgo[make_pair(1, 0)] = 'D';
	vector<vector<bool>> arr(b + 2, vector<bool>(b + 2, false));
	set<pair<ll, ll>> snow;
	vector<pair<ll, ll>> all;
	ll max_col = sqrt(sqrt(b)) * sqrt(sqrt(sqrt(b)));
	//ll max_col = min(100ll, b);
	ll stack = 0;
	for (ll t = 0; t < 2000; t++) {
		ll col_old = all.size();
		vector<pair<ll, ll>> nall;
		vector<vector<ll>> dist(b + 2, vector<ll>(b + 2, -1));
		ll k;
		cin >> k;
		for (ll i = 0; i < k; i++) {
			ll a, b;
			cin >> a >> b;
			snow.insert({a, b});
			arr[a + 1][b + 1] = true;
		}
		vector<tuple<char, ll, ll>> commands;
		queue<pair<ll, ll>> q;
		for (ll i = 1; i <= b; i++) {
			dist[0][i] = 0;
			dist[i][0] = 0;
			dist[i][b + 1] = 0;
			dist[b + 1][i] = 0;
			for (ll j = 1; j <= b; j++) {
				if (arr[i][j]) {
					q.push(make_pair(i, j));
					dist[i][j] = 0;
				}
			}
		}
		ll mx = 0;
		while (!q.empty()) {
			auto[i, j] = q.front();
			q.pop();
			for (auto[x, y] : go) {
				if (dist[i + x][j + y] == -1) {
					dist[i + x][j + y] = dist[i][j] + 1;
					q.push(make_pair(i + x, j + y));
					assign_max(mx, dist[i][j] + 1);
				}
			}
		}
		for (ll i = 1; i <= b; i++) {
			for (ll j = 1; j <= b; j++) {
				dist[i][j] = mx - dist[i][j];
				dist[i][j] = dist[i][j] * dist[i][j] * dist[i][j] * dist[i][j] * dist[i][j];
				dist[i][j]++;
			}
		}
		//ll ccc = max(1ll, min(30ll, 100 - s + f));
		ll ccc = 100;
		ll re = 1;
		for (ll i = 0; i < col_old; i++) {
			ll col = 0;
			for (auto[x, y] : go) {
				//col += dist[all[i].first + x + 1][all[i].second + y + 1];
				if (arr[all[i].first + x + 1][all[i].second + y + 1]) {
					col += 1000;
				} else {
					//col++;
				}
				if (all[i].first + x >= b || all[i].second + y >= b || all[i].first + x < 0 || all[i].second + y < 0) {
					//col--;
				}
			}
			if (col == 0) {
				vector<pair<ll, ll>> a;
				ll sm = 0, mx = 0;
				for (ll j = 0; j < 5; j++) {
					auto[x, y] = go[j];
					//if (!(all[i].first + x >= b || all[i].second + y >= b || all[i].first + x < 0 || all[i].second + y < 0)) {
					ll nn = 1;
					if ((all[i].first + x >= b || all[i].second + y >= b || all[i].first + x < 0 || all[i].second + y < 0)) {
						continue;
					}
					for (auto[xx, yy] : snow) {
						if (j == 0) {
							continue;
						}
						if (j == 1) {
							if (xx <= all[i].first) {
								continue;
							}
						}
						if (j == 2) {
							if (xx >= all[i].first) {
								continue;
							}
						}
						if (j == 3) {
							if (yy <= all[i].second) {
								continue;
							}
						}
						if (j == 4) {
							if (yy >= all[i].second) {
								continue;
							}
						}
						ll nnn = (abs(all[i].first + x - xx) + abs(all[i].second + y - yy));
						assign_max(mx, nnn);
						//nn += nnn * nnn * nnn * nnn * nnn * nnn * nnn * nnn * sqrt(nnn);
					}
					//for (auto[xx, yy] : snow) {
					//	bool b = true;
					//	ll nnn = b * 2 - (abs(all[i].first + x - xx) + abs(all[i].first + x - xx));
					//	for (ll k = 0; k < 5; j++) {
					//		if (nnn > b * 2 - (abs(all[i].first + go[k].first - xx) + abs(all[i].first + go[k] - xx));
					//	}
					//	nn += nnn * nnn * nnn * nnn * nnn * nnn;
					//}
					//if ((all[i].first + x >= b || all[i].second + y >= b || all[i].first + x < 0 || all[i].second + y < 0)) {
					//	nn = 0;
					//}
					//a.push_back(make_pair(j, dist[all[i].first + x + 1][all[i].second + y + 1]));
					//a.push_back(make_pair(j, nn));
					//sm += a.back().second;
					//}
				}
				for (ll j = 0; j < 5; j++) {
					auto[x, y] = go[j];
					//if (!(all[i].first + x >= b || all[i].second + y >= b || all[i].first + x < 0 || all[i].second + y < 0)) {
					ll nn = 1;
					for (auto[xx, yy] : snow) {
						if (j == 0) {
							continue;
						}
						if (j == 1) {
							if (xx <= all[i].first) {
								continue;
							}
						}
						if (j == 2) {
							if (xx >= all[i].first) {
								continue;
							}
						}
						if (j == 3) {
							if (yy <= all[i].second) {
								continue;
							}
						}
						if (j == 4) {
							if (yy >= all[i].second) {
								continue;
							}
						}
						ll nnn = mx - (abs(all[i].first + x - xx) + abs(all[i].second + y - yy));
						nn += nnn * nnn * nnn * nnn * nnn * nnn * nnn * nnn * sqrt(nnn);
					}
					//for (auto[xx, yy] : snow) {
					//	bool b = true;
					//	ll nnn = b * 2 - (abs(all[i].first + x - xx) + abs(all[i].first + x - xx));
					//	for (ll k = 0; k < 5; j++) {
					//		if (nnn > b * 2 - (abs(all[i].first + go[k].first - xx) + abs(all[i].first + go[k] - xx));
					//	}
					//	nn += nnn * nnn * nnn * nnn * nnn * nnn;
					//}
					if ((all[i].first + x >= b || all[i].second + y >= b || all[i].first + x < 0 || all[i].second + y < 0)) {
						nn = 0;
					}
					//a.push_back(make_pair(j, dist[all[i].first + x + 1][all[i].second + y + 1]));
					a.push_back(make_pair(j, nn));
					sm += a.back().second;
					//}
				}
				ll now = rnd() % sm;
				ll ans;
				for (auto[i, j] : a) {
					auto[x, y] = go[i];
					now -= j;
					ans = i;
					if (now < 0) {
						break;
					}
				}
				auto[xx, yy] = go[ans];
				nall.push_back(make_pair(all[i].first + xx, all[i].second + yy));
				if (xx != 0 || yy != 0) {
					commands.push_back(make_tuple('M', i, xx * 1000 + yy));
				}
				continue;
			}
			ll now = rnd() % col;
			for (auto[x, y] : go) {
				//now -= dist[all[i].first + x + 1][all[i].second + y + 1];
				if (arr[all[i].first + x + 1][all[i].second + y + 1]) {
					now -= 1000;
				} else {
					//now--;
				}
				if (all[i].first + x >= b || all[i].second + y >= b || all[i].first + x < 0 || all[i].second + y < 0) {
					//now++;
					continue;
				}
				if (now < 0) {
					if (x != 0 || y != 0) {
						commands.push_back(make_tuple('M', i, x * 1000 + y));
					}
					arr[all[i].first + x + 1][all[i].second + y + 1] = false;
					if (snow.find(make_pair(all[i].first + x, all[i].second + y)) != snow.end()) {
						snow.erase(make_pair(all[i].first + x, all[i].second + y));
					}
					nall.push_back(make_pair(all[i].first + x, all[i].second + y));
					break;
				}
			}
			{
				dist.clear();
				dist.resize(b + 2, vector<ll>(b + 2, -1));
				for (ll i = 1; i <= b; i++) {
					dist[0][i] = 0;
					dist[i][0] = 0;
					dist[i][b + 1] = 0;
					dist[b + 1][i] = 0;
					for (ll j = 1; j <= b; j++) {
						if (arr[i][j]) {
							q.push(make_pair(i, j));
							dist[i][j] = 0;
						}
					}
				}
				mx = 0;
				while (!q.empty()) {
					auto[i, j] = q.front();
					q.pop();
					for (auto[x, y] : go) {
						if (dist[i + x][j + y] == -1) {
							dist[i + x][j + y] = dist[i][j] + 1;
							q.push(make_pair(i + x, j + y));
							assign_max(mx, dist[i][j] + 1);
						}
					}
				}
				for (ll i = 1; i <= b; i++) {
					for (ll j = 1; j <= b; j++) {
						dist[i][j] = mx - dist[i][j];
						dist[i][j] = dist[i][j] * dist[i][j] * dist[i][j] * dist[i][j] * dist[i][j];
						dist[i][j]++;
					}
				}
			}
		}
		while (all.size() < max_col && (rnd() % 100 <= ccc) && !snow.empty()) {
			ll a = rnd() % b, c = rnd() % b;
			auto it = snow.upper_bound(make_pair(a, c));
			if (it == snow.end()) {
				it--;
			}
			auto[aa, cc] = *it;
			commands.push_back(make_tuple('H', aa, cc));
			nall.push_back(make_pair(aa, cc));
			all.push_back(make_pair(aa, cc));
			arr[aa + 1][cc + 1] = false;
			snow.erase(snow.find(make_pair(aa, cc)));
		}
		if (max_col < b * f / s) {
			if (snow.size() > max_col * (2000 - t) * s / (b * b / max_col * f * b / 2.25)) {
				stack++;
			} else {
				stack = 0;
			}
			if (stack > max_col * (2000 - t) * s / (b * b / max_col * f * b / 2.25)) {
				max_col++;
				stack = 0;
			}
		}
		//if (max_col < 100) {
		//	if (snow.size() > max_col) {
		//		stack++;
		//	} else {
		//		stack = 0;
		//	}
		//	if (stack > 10) {
		//		max_col++;
		//		stack = 0;
		//	}
		//}
		cout << commands.size() << endl;
		for (auto[a, b, c] : commands) {
			if (a == 'H') {
				cout << a << ' ' << b << ' ' << c << endl;
			} else {
				cout << a << ' ' << b << ' ' << cgo[make_pair(c / 1000, c % 1000)] << endl;
			}
		}
		all = nall;
	}
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
