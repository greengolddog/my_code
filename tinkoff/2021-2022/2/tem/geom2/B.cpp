#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF = 9'000'000'000'000'000'000, MAX = 1'000'000'000;
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

double dist(pair<ll, ll> p1, pair<ll, ll> p2) {
	return sqrt(square(p1.first - p2.first) + square(p1.second - p2.second));
}

ll h(pair<ll, ll> p) {
	return p.first * MAX * 2 + p.second;
}

void solve() {
	ll n;
	cin >> n;
	deque<pair<ll, ll>> arr(n);
	for (auto&[a, b] : arr) {
		cin >> a >> b;
		a += MAX;
		b += MAX;
	}
	shuffle(arr.begin(), arr.end(), rnd64);
	pair<ll, ll> p1 = arr[0], p2 = arr[1];
	double sz = dist(p1, p2);
	//ll sz = 1'000'000'000'000;
	unordered_map<ll, vector<pair<ll, ll>>> ap;
	ap.reserve(n);
	ap[h(make_pair(floor(p1.first / sz), floor(p1.second / sz)))].push_back(p1);
	ap[h(make_pair(floor(p2.first / sz), floor(p2.second / sz)))].push_back(p2);
	vector<pair<ll, ll>> old;
	old.push_back(arr[0]);
	old.push_back(arr[0]);
	arr.pop_front();
	arr.pop_front();
	for (auto i : arr) {
		ll c1 = floor(i.first / sz), c2 = floor(i.second / sz);
		bool b = false;
		for (ll x = -1; x < 2; x++) {
			for (ll y = -1; y <= 2; y++) {
				for (auto p : ap[h(make_pair(c1 + x, c2 + y))]) {
					if (dist(p, i) < dist(p1, p2)) {
						p1 = i;
						p2 = p;
						b = true;
					}
				}
			}
		}
		if (b) {
			sz = dist(p1, p2);
			//sz = 1'000'000'000'000;
			ap.clear();
			for (auto j : old) {
				ap[h(make_pair(floor(j.first / sz), floor(j.second / sz)))].push_back(j);
			}
		}
		ap[h(make_pair(floor(i.first / sz), floor(i.second / sz)))].push_back(i);
		old.push_back(i);
	}
	cout << p1.first - MAX << ' ' << p1.second - MAX << '\n' << p2.first - MAX << ' ' << p2.second - MAX << '\n';
}

void solve2() {
	ll n;
	cin >> n;
	deque<pair<ll, ll>> arr(n);
	for (auto&[a, b] : arr) {
		cin >> a >> b;
		a += MAX;
		b += MAX;
	}
	pair<ll, ll> p1 = arr[0], p2 = arr[1];
	for (ll i = 0; i < n; i++) {
		for (ll j = i + 1; j < n; j++) {
			if (dist(arr[i], arr[j]) < dist(p1, p2)) {
				p1 = arr[i];
				p2 = arr[j];
			}
		}
	}
	cout << p1.first - MAX << ' ' << p1.second - MAX << '\n' << p2.first - MAX << ' ' << p2.second - MAX << '\n';
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
