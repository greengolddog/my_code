#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
const db PI = acos(-1);

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

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

template<typename T>
T square(T a) {
	return a * a;
}

template<>
struct std::hash<pair<ll, ll>> {
	ll operator() (pair<ll, ll> p) {
		return ((__int128)p.first * MOD + p.second) % INF64;
	}
};

bool check(ll n, ll m, vector<vector<ll>> arr, vector<pair<ll, ll>> num) {
	vector<vector<bool>> used(n, vector<bool>(m, false));
	used[num[0].first][num[0].second] = true;
	vector<pair<ll, ll>> go;
	go.push_back(make_pair(1, 0));
	go.push_back(make_pair(-1, 0));
	go.push_back(make_pair(0, 1));
	go.push_back(make_pair(0, -1));
	for (ll i = 1; i < n * m; i++) {
		auto[x, y] = num[i];
		bool b = false;
		for (auto[px, py] : go) {
			if (x + px >= 0 && x + px < n && y + py >= 0 && y + py < m) {
				if (used[x + px][y + py]) {
					b = true;
					break;
				}
			}
		}
		used[x][y] = b;
		if (!b) {
			return false;
		}
	}
	return true;
}

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<pair<ll, ll>> num(n * m);
	vector<vector<ll>> arr(n, vector<ll>(m));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> arr[i][j];
			arr[i][j]--;
			num[arr[i][j]] = make_pair(i, j);
		}
	}
	if (check(n, m, arr, num)) {
		cout << 0 << '\n';
		return;
	}
	if (n * m <= 100) {
		ll aa = 0;
		for (ll i = 0; i < n * m; i++) {
			for (ll j = 0; j < n * m; j++) {
				auto[xi, yi] = num[i];
				auto[xj, yj] = num[j];
				swap(num[i], num[j]);
				swap(arr[xi][yi], arr[xj][yj]);
				if (check(n, m, arr, num)) {
					aa++;
				}
				swap(num[i], num[j]);
				swap(arr[xi][yi], arr[xj][yj]);
			}
		}
		if (aa > 0) {
			cout << 1 << ' ' << aa / 2 << '\n';
		} else {
			cout << 2 << '\n';
		}
		return;
	}
	vector<ll> nr;
	ll cv = -1;
	vector<vector<bool>> used(n, vector<bool>(m, false));
	used[num[0].first][num[0].second] = true;
	vector<pair<ll, ll>> go;
	go.push_back(make_pair(1, 0));
	go.push_back(make_pair(-1, 0));
	go.push_back(make_pair(0, 1));
	go.push_back(make_pair(0, -1));
	ll col = 0, ce = 0, ac = 0, cc = 0;
	for (ll i = 1; i < n * m; i++) {
		auto[x, y] = num[i];
		bool bcv = false, b = false;
		for (auto[px, py] : go) {
			if (x + px >= 0 && x + px < n && y + py >= 0 && y + py < m) {
				if (used[x + px][y + py]) {
					if (arr[x + px][y + py] == cv) {
						bcv = true;
					} else {
						b = true;
					}
				}
			}
		}
		if (!b) {
			if (cv == -1) {
				cv = i;
				for (ll i = 1; i < n * m; i++) {
					auto[x, y] = num[i];
					if (used[x][y]) {
						continue;
					}
					bool bb = false;
					for (auto[px, py] : go) {
						if (x + px >= 0 && x + px < n && y + py >= 0 && y + py < m) {
							if (used[x + px][y + py]) {
								bb = true;
								break;
							}
						}
					}
					if (bb) {
						nr.push_back(i);
					}
				}
				for (auto[px, py] : go) {
					auto[x, y] = num[i];
					auto[x0, y0] = num[i - 1];
					x += px;
					y += py;
					if (x >= 0 && x < n && y >= 0 && y < m) {
						swap(arr[x0][y0], arr[x][y]);
						swap(num[arr[x0][y0]], num[i - 1]);
						if (check(n, m, arr, num)) {
							ce++;
						}
						swap(num[arr[x0][y0]], num[i - 1]);
						swap(arr[x0][y0], arr[x][y]);
					}
				}
				ce *= i - 1;
				if (n * m <= 2000) {
					ll aa = 0;
					for (ll j = 1; j < n * m; j++) {
						auto[xi, yi] = num[i];
						auto[xj, yj] = num[j];
						swap(num[i], num[j]);
						swap(arr[xi][yi], arr[xj][yj]);
						if (check(n, m, arr, num)) {
							aa++;
						}
						swap(num[i], num[j]);
						swap(arr[xi][yi], arr[xj][yj]);
					}
					if (aa + ce > 0) {
						cout << 1 << ' ' << aa + ce << '\n';
					} else {
						cout << 2;
					}
					return;
				}
				sort(nr.begin(), nr.end());
				reverse(nr.begin(), nr.end());
			} else {
				for (auto[px, py] : go) {
					auto[x, y] = num[i];
					auto[x0, y0] = num[cv];
					x += px;
					y += py;
					if (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] >= i) {
						swap(arr[x0][y0], arr[x][y]);
						swap(num[arr[x0][y0]], num[cv]);
						if (check(n, m, arr, num)) {
							col++;
						}
						swap(num[arr[x0][y0]], num[cv]);
						swap(arr[x0][y0], arr[x][y]);
					}
				}
				if (bcv) {
					assign_min(ac, cc);
				} else {
					if (col + ce > 0) {
						cout << 1 << ' ' << col + ce << '\n';
						return;
					} else {
						cout << 2 << '\n';
						return;
					}
				}
			}
		}
		used[x][y] = b;
		if (!nr.empty() && nr.back() == i) {
			if (ac != 0) {
				nr.pop_back();
				cc++;
				continue;
			}
			auto[xc, yc] = num[cv];
			bool bb = false;
			for (auto[px, py] : go) {
				if (xc + px >= 0 && xc + px < n && yc + py >= 0 && yc + py < m) {
					if (used[xc + px][yc + py]) {
						bb = true;
						break;
					}
				}
			}
			if (bb) {
				used[xc][yc] = true;
				ac = nr.size();
			}
			nr.pop_back();
			cc = 1;
		}
	}
	if (ac + ce > 0) {
		cout << 1 << ' ' << ac + ce << '\n';
	} else {
		cout << 2 << '\n';
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	//cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}
