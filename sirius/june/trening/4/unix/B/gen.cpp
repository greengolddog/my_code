#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll INF32 = 2'000'000'000, INF64 = 9'000'000'000'000'000'000;

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
	ll n, q;
	cin >> n >> q;
	vector<ll> arr;
	for (ll i = 1; i <= n; i++) {
		arr.push_back(i);
		arr.push_back(i);
	}
	shuffle(arr.begin(), arr.end(), rnd32);
	cout << n << ' ' << q << '\n';
	for (auto i : arr) {
		cout << i << ' ';
	}
	cout << '\n';
	for (ll i = 0; i < q; i++) {
		ll a = rnd32() % n, b = rnd32() % n;
		cout << a + 1 << ' ' << b + 1 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
