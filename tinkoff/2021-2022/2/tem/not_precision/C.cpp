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

mt19937_64 rnd(time(0));

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	ll minx = 1'000'000, maxx = 0, miny = 1'000'000, maxy = 0;
	for (ll i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		assign_min(minx, x);
		assign_max(maxx, x);
		assign_min(miny, y);
		assign_max(maxy, y);
	}
	for (ll i = 0; i < k; i++) {
		cout << (double)(rnd() % (1'000'000 * (maxx - minx + 1)) + 1'000'000 * minx) / 1'000'000 << ' ';
		cout << (double)(rnd() % (1'000'000 * (maxy - miny + 1)) + 1'000'000 * miny) / 1'000'000 << '\n';
	}
}
