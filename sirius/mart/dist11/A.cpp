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

void solve() {
	ll a, b;
	cin >> a >> b;
	ll ans = ((b + a - 1) / a) * a - b ;
	for (ll i = 2; i * i <= a; i++) {
		if (a % i == 0) {
			assign_min(ans, ((b + i - 1) / i) * i - b);
			ll j = a / i;
			assign_min(ans, ((b + j - 1) / j) * j - b);
		}
	}
	cout << ans << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		solve();
	}
}
