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
	ll on = n;
	deque<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		char c;
		cin >> c;
		arr[i] = c - '0';
	}
	arr.front()++;
	ll x = 10 - arr.back();
	arr.back() += x;
	for (ll i = n - 1; i > 0; i--) {
		if (arr[i] > 9) {
			arr[i] -= 10;
			arr[i - 1]++;
		}
	}
	if (arr.front() > 9) {
		arr.front() -= 10;
		arr.push_front(1);
		n++;
	}
	deque<ll> ans(n, 0);
	for (ll i = 0; i < n / 2; i++) {
		if (arr[i] > arr[n - i - 1]) {
			ans[n - i - 1] += arr[i] - arr[n - i - 1];
		} else {
			ans[i] += arr[n - i - 1] - arr[i];
		}
	}
	ans[n - on]++;
	ans.back() += x;
	for (ll i = n - 1; i > 0; i--) {
		if (ans[i] > 9) {
			ans[i] -= 10;
			ans[i - 1]++;
		}
	}
	if (ans.front() > 9) {
		ans.front() -= 10;
		ans.push_front(1);
		n++;
	}
	bool b = false;
	for (auto i : ans) {
		if (b || i != 0) {
			cout << i;
			b = true;
		}
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
