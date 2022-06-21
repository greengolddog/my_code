#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll INF32 = 2'000'000'000, INF64 = 9'000'000'000'000'000'000, LOG = 25;

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

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

void solve() {
	ll n, h = 0;
	cin >> n;
	vector<ll> arr;
	for (ll i = 0; i < n; i++) {
		arr.push_back(rnd32() % 1'000'001);
		h += arr.back();
	}
	cout << n << ' ' << rnd64() % h << '\n';
	for (ll i = 0; i < n; i++) {
		cout << 0 << ' ';
	}
	cout << '\n';
	for (auto i : arr) {
		cout << i << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
