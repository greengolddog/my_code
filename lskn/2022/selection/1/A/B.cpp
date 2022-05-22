#pragma GCC optimize("Ofast")
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

pair<ll, ll> m(pair<ll, ll> a1, pair<ll, ll> a2) {
	return make_pair(a1.first - a2.first, a1.second - a2.second);
}

void solve() {
	ll n;
	cin >> n;
	vector<pair<ll, ll>> arr(n);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	vector<pair<ll, ll>> all;
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			if (i != j) {
				all.push_back(m(arr[i], arr[j]));
			}
		}
	}
	stable_sort(all.begin(), all.end());
	ll now = 0;
	for (ll i = 1; i < all.size(); i++) {
		if (all[i] == all[i - 1]) {
			now++;
		} else {
			now = 0;
		}
		ans += now;
	}
	cout << ans / 4 << '\n';
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
