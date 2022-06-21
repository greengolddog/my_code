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
	ll col = 0;
	for (ll i = 0; i < n * m; i++) {
		for (ll j = 0; j < n * m; j++) {
			auto[xi, yi] = num[i];
			auto[xj, yj] = num[j];
			swap(arr[xj][yj], arr[xi][yi]);
			swap(num[i], num[j]);
			if (check(n, m, arr, num)) {
				col++;
			}
			swap(arr[xj][yj], arr[xi][yi]);
			swap(num[i], num[j]);
		}
	}
	if (col == 0) {
		cout << 2 << '\n';
	} else {
		cout << 1 << ' ' << col / 2 << '\n';
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
