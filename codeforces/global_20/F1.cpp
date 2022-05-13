#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF = 9'000'000'000'000'000'000;
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

void solve() {
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<pair<ll, ll>> a;
	for (ll i = 0; i < n; i++) {
		a.push_back(make_pair(arr[i], i));
	}
	sort(a.begin(), a.end());
	deque<ll> f, s;
	for (auto[ff, ss] : a) {
		f.push_back(ff);
		s.push_back(ss);
	}
	for (ll i = 0; i < n / 2; i++) {
		s.push_front(s.back());
		s.pop_back();
	}
	vector<ll> ans(n, 0);
	for (ll i = 0; i < n; i++) {
		ans[s[i]] = f[i];
	}
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << '\n';
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
