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

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll ans = 1;
	ll col;
	cin >> col;
	ll x = 2;
	while (col > 0) {
		bool b = true;
		for (ll i = 2; i * i <= x; i++) {
			if (x % i == 0) {
				b = false;
				break;
			}
		}
		if (b) {
			ans *= x;
			col--;
		}
		x++;
	}
	cout << ans;
}
