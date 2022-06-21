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

void solve() {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	vector<pair<ll, ll>> arr;
	for (ll i = 0; i < s.size(); i++) {
		ll x = s[i] == '(';
		if (!arr.empty() && x != arr.back().first) {
			arr.pop_back();
		} else {
			arr.push_back(make_pair(x, i + 1));
		}
	}
	if (arr.size() == 0) {
		cout << 0 << '\n';
		return;
	}
	if (arr[0] == arr.back()) {
		cout << 1 << '\n';
		cout << arr[arr.size() / 2].second << ' ' << s.size() << '\n';
		return;
	}
	vector<pair<ll, ll>> x0, x1;
	for (auto i : arr) {
		if (i.first == 0) {
			x0.push_back(i);
		} else {
			x1.push_back(i);
		}
	}
	cout << 2 << '\n';
	cout << x1[0].second << ' ' << s.size() << '\n';
	cout << arr[arr.size() / 2].second << ' ' << s.size() << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}
